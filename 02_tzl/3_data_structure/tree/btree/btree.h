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
     

        return NULL;
    }
    SharedPointer< Tree<T> > remove(TreeNode<T> *node)
    {

        return NULL;
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
    int degree() const // 获取树的度
    {
        return 0;
    }
    int count() const  // 获取树的节点数
    {
        return 0;
    }
    int height() const // 获取树的高度
    {
        return 0;
    }
    void clear()       // 清空树中的元素
    {
        this->m_root = NULL;
    }

    ~BTree()
    {
        clear();
    }

};

}



#endif