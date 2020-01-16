/*
 *           Object
 *        ^         ^
 *        |         |
 *      Tree ----> TreeNode
 *        ^           ^
 *        |           |
 *     BTree -----> BTreeNode 
 */

#ifndef BTREE_H
#define BTREE_H

#include "tree.h"
#include "btree_node.h"

// for clear() test
#if 0
#include <iostream>
#endif

namespace DTLib {

enum BTNodePos {
    ANY,
    LEFT,
    RIGHT
};

template <typename T>
class BTree : public Tree<T> {
protected:
    virtual BTreeNode<T> *find(BTreeNode<T> *node, const T &value) const
    {
        BTreeNode<T> *ret = NULL;

        if (node != NULL) {
            if (node->value == value) {
                ret = node;
            } else {
                if (ret == NULL) {
                    ret = find(node->left, value);
                }
                if (ret == NULL) {
                    ret = find(node->right, value);
                }
            }
        }
        return ret;
    }
    virtual BTreeNode<T> *find(BTreeNode<T> *node, BTreeNode<T> *obj) const
    {
        BTreeNode<T> *ret = NULL;

        if (node == obj) {
            ret = node;
        } else {
            if (node != NULL) {
                if (ret == NULL) {
                    ret = find(node->left, obj);
                }
                if (ret == NULL) {
                    ret = find(node->right, obj);
                }
            }
        }
        return ret;
    }

    /*
     * n   : 要插入的节点
     * np  : 要插入的节点的父节点
     * pos : 插入的位置
     */
    virtual bool insert(BTreeNode<T> *n, BTreeNode<T> *np, BTNodePos pos)
    {
        bool ret = true;
        if (pos == ANY) {
            if (np->left == NULL) {
                np->left = n;
            } else if (np->right == NULL) {
                np->right = n;
            } else {
                ret = false;
            }
        } else if (pos == LEFT) {
            if (np->left == NULL) {
                np->left = n;
            } else {
                ret = false;
            }
        } else if (pos == RIGHT) {
            if (np->right == NULL) {
                np->right = n;
            } else {
                ret = false;
            }
        } else {
            ret = false;
        }
        return ret;
    }

    virtual void remove(BTreeNode<T> *node, BTree<T> *&ret)
    {
        ret = new BTree<T>();
        if (ret == NULL) {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create new tree ...");
        } else {
            if (root() == node) {
                this->m_root = NULL;
            } else {
                BTreeNode<T> *parent = dynamic_cast<BTreeNode<T>*>(node->parent);
                if (parent->left == node) {
                    parent->left = NULL;
                } else if (parent->right == node) {
                    parent->right = NULL;
                }
                node->parent = NULL;
            }
            ret->m_root = node;
        }
    }

    virtual void free(BTreeNode<T> *node)
    {
        if (node != NULL)
        {
            free(node->left);
            free(node->right);
#if 0   // for clear() test
            std::cout << node->value << std::endl;
#endif
            if (node->flag()) {
                delete node;
            }
        }
    }

    int count(BTreeNode<T> *node) const
    {
#if 0
        int ret = 0;
        if (node != NULL) {
            ret = count(node->left) + count(node->right) + 1;
        }
        return ret;
#else // 简单写法
        return (node != NULL) ? (count(node->left) + count(node->right) + 1) : 0;
#endif
    }

    int height(BTreeNode<T> *node) const
    {
        int ret = 0;
        if (node != NULL) {
            int lh = height(node->left);
            int rh = height(node->right);
            ret = ((lh > rh) ? lh : rh) + 1;
        }
        return ret;
    }
    int degree(BTreeNode<T> *node) const
    {
        int ret = 0;
        if (node != NULL) {
#if 1 // 稍微高效一点
            BTreeNode<T> *child[] = { node->left, node->right };
            ret = (!!node->left + !!node->right);
            for (int i = 0; (i < 2) && (ret < 2); i++) {
                int d = degree(child[i]);
                if (ret < d) {
                    ret = d;
                }
            }
#else
            int ld = degree(node->left);
            int rd = degree(node->right);

            ret = (!!node->left + !!node->right);

            if (ret < ld) {
                ret = ld;
            }
            if (ret < rd) {
                ret = rd;
            }
#endif
        }
        return ret;
    }
public:
    // implementation
    bool insert(TreeNode<T> *node)
    {
        return insert(node, ANY);
    }
    virtual bool insert(TreeNode<T> *node, BTNodePos pos)
    {
        bool ret = true;

        if (node != NULL) {
            if (this->m_root == NULL) {
                node->parent = NULL;
                this->m_root = node;
            } else {
                BTreeNode<T> *np = find(node->parent);
                if (np != NULL) {
                    ret = insert(dynamic_cast<BTreeNode<T>*>(node), np, pos);
                } else {
                    THROW_EXCEPTION(InvalidParameterException, "Invalid parent tree node ...");
                }
            }
        } else {
            THROW_EXCEPTION(InvalidParameterException, "Parameter node can not be NULL ...");
        }

        return ret;
    }
    bool insert(const T &value, TreeNode<T> *parent)
    {
        return insert(value, parent, ANY);
    }
    virtual bool insert(const T &value, TreeNode<T> *parent, BTNodePos pos)
    {
        bool ret = true;
        BTreeNode<T> *node = BTreeNode<T>::NewNode();
        if (node == NULL) {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create new node ...");
        } else {
            node->value = value;
            node->parent = parent;
            ret = insert(node, pos);
            if (!ret) {
                delete node; // 若父节点不存在，需销毁创建的节点
            }
        }
        return ret;
    }

    SharedPointer< Tree<T> > remove(const T &value)
    {
        BTree<T> *ret = NULL;
        BTreeNode<T> *node = find(value);

        if (node == NULL) {
            THROW_EXCEPTION(InvalidParameterException, "Can not find the tree node via value ...");
        } else {
            remove(node, ret);
        }

        return ret;
    }
    SharedPointer< Tree<T> > remove(TreeNode<T> *node)
    {
        BTree<T> *ret = NULL;

        node = find(node);
        if (node == NULL) {
            THROW_EXCEPTION(InvalidParameterException, "Parameter node is invalid ...");
        } else {
            remove(dynamic_cast<BTreeNode<T>*>(node), ret);
        }

        return ret;
    }
    
    /*
     *                   | return node;                                             node->value == value
     * find(node, value) |
     *                   | find(node->left, value); or find(node->right, value);    node->value != value
     */
    BTreeNode<T> *find(const T &value) const // 递归方法进行查找
    {
        return find(root(), value);
    }
    /*
     *                 | return node;                                         node == obj
     * find(node, obj) |
     *                 | find(node->left, obj); or find(node->right, obj);    node != obj
     */
    BTreeNode<T> *find(TreeNode<T> *node) const // 递归方法进行查找
    {
        return find(root(), dynamic_cast<BTreeNode<T>*>(node));
    }
    BTreeNode<T> *root() const // 访问树的根节点
    {
        return dynamic_cast<BTreeNode<T>*>(this->m_root);
    }

    // 获取树的属性
    /*
     *              | return 0;                                                                     node == NULL
     * degree(node) |
     *              | MAX{degree(node->left), degree(node->left), !!node->left + !!node->right};    node != NULL
     *                                                                (node节点的degree)
     */
    int degree() const // 递归方法，获取树的度
    {
        return degree(root());
    }
    /*
     *             | return 0;                                      node == NULL
     * count(node) |
     *             | count(node->left) + count(node->right) + 1;    node != NULL
     */
    int count() const  // 递归方法，获取树的节点数
    {
        return count(root());
    }
    /*
     *              | return 0;                                         node == NULL
     * height(node) |
     *              | MAX{height(node->left), height(node->right)} + 1;  node != NULL
     */
    int height() const // 递归方法，获取树的高度
    {
        return height(root());
    }
    
    /* clear 操作注意是否对空间创建的节点 */
    /*
     *            | return ;                                            node == NULL
     * free(node) | 
     *            | free(node->left); free(node->right); delete node;   node != NULL
     */
    void clear()       // 递归方法，清空树中的元素
    {
        free(root());
        this->m_root = NULL;
    }

    ~BTree()
    {
        clear();
    }

};

}



#endif