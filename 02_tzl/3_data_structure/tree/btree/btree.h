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
#include "link_queue.h"
#include "dynamic_array.h"
// for clear() test
#if 0
#include <iostream>
#endif

namespace DTLib {

enum BTTraversal {
    PreOrder,
    InOrder,
    PostOrder
};

template <typename T>
class BTree : public Tree<T> {
protected:
    /* 层次遍历所需队列 */
    LinkQueue<BTreeNode<T>*> m_queue;

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

    void preOrderTraversal(BTreeNode<T> *node, LinkQueue<BTreeNode<T>*> &queue)
    {
        if (node != NULL) {
            queue.add(node);
            preOrderTraversal(node->left, queue);
            preOrderTraversal(node->right, queue);
        }
    }

    void inOrderTraversal(BTreeNode<T> *node, LinkQueue<BTreeNode<T>*> &queue)
    {
        if (node != NULL) {
            inOrderTraversal(node->left, queue);
            queue.add(node);
            inOrderTraversal(node->right, queue);
        }
    }

    void postOrderTraversal(BTreeNode<T> *node, LinkQueue<BTreeNode<T>*> &queue)
    {
        if (node != NULL) {
            postOrderTraversal(node->left, queue);
            postOrderTraversal(node->right, queue);
            queue.add(node);
        }
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
            m_queue.clear();
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
            m_queue.clear();
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
    
#if 1
    // 树形结构的层次遍历 相关函数
    bool begin() // 初始化，准备进行遍历访问
    {
        bool ret = (root() != NULL);
        if (ret) {
            m_queue.clear();
            m_queue.add(root());
        }
        return ret;
    }
    bool end() // 判断游标是否达到尾部
    {
        return (m_queue.length() == 0);
    }
    bool next() // 移动游标，指向下一个节点
    {
        bool ret = (m_queue.length() > 0);
        if (ret) {
            BTreeNode<T> *node = m_queue.front();
            m_queue.remove();
            if (node->left != NULL) {
                m_queue.add(node->left);
            }
            if (node->right != NULL) {
                m_queue.add(node->right);
            }
        }

        return ret;
    }
    T current() // 获取游标所指定的数据元素
    {
        if (!end()) {
            return m_queue.front()->value;
        } else {
            THROW_EXCEPTION(InvalidOperationException, "No value at current position ...");
        }
    }
#endif

    /* clear 操作注意是否对空间创建的节点 */
    /*
     *            | return ;                                            node == NULL
     * free(node) | 
     *            | free(node->left); free(node->right); delete node;   node != NULL
     */
    void clear()       // 递归方法，清空树中的元素
    {
        free(root());
        m_queue.clear();
        this->m_root = NULL;
    }

    /*
     * 典型的二叉树遍历方式 (递归方法遍历)
     *  - 先序遍历(Pre-Order Traversal)
     *      - 二叉树为空：
     *          无操作
     *      - 二叉树不为空
     *          1. 访问根节点中的数据元素 ("先"的含义是, 先访问根节点中的数据元素)
     *          2. 先序遍历左子树
     *          3. 先序遍历右子树
     *      伪代码：
     *      PreOrderTraversal(node) {
     *          if (node != NULL) {
     *              access(node->value);
     *              PreOrderTraversal(node->left);
     *              PreOrderTraversal(node->right);
     *          }
     *      }
     *  - 中序遍历(In-Order Traversal)
     *      - 二叉树为空：
     *          无操作，直接返回
     *      - 二叉树不为空
     *          1. 中序遍历左子树
     *          2. 访问根节点中的数据元素 ("中"的含义是，在中间的时候访问根节点中的数据元素)
     *          3. 中序遍历右子树
     *      伪代码：
     *      InOrderTraversal(node) {
     *          if (node != NULL) {
     *              InOrderTraversal(node->left);
     *              access(node->value);
     *              InOrderTraversal(node->right);
     *          }
     *      }
     * - 后序遍历(Post-Order Traversal)
     *      - 二叉树为空：
     *          无操作，直接返回
     *      - 二叉树不为空
     *          1. 后序遍历左子树
     *          2. 后序遍历右子树
     *          3. 访问根节点中的数据元素 ("后"的含义是，最后访问根节点中的数据元素)
     *      伪代码：
     *      PostOrderTraversal(node) {
     *          if (node != NULL) {
     *              PostOrderTraversal(node->left);
     *              PostOrderTraversal(node->right);
     *              access(node->value);
     *          }
     *      }
     * 
     *  用户调用示例
     *      SharedPointer< Array<int> > sp = NULL;
     *      sp = tree.traversal(PreOrder);
     *      for(int i = 0; i < (*sp).length(); i++) {
     *          cout << (*sp)[i] << endl;
     *      }
     */
    SharedPointer< Array<T> > traversal(BTTraversal order)
    {
        DynamicArray<T> *ret = NULL;
        LinkQueue<BTreeNode<T>*> queue; //用来保存遍历节点的次序

        switch(order) {
            case PreOrder:
                preOrderTraversal(root(), queue);
                break;
            case InOrder:
                inOrderTraversal(root(), queue);
                break;
            case PostOrder:
                postOrderTraversal(root(), queue);
                break;
            default:
                THROW_EXCEPTION(InvalidParameterException, "Parameter order is invalid ...");
                break;
        }

        ret = new DynamicArray<T>(queue.length());
        if (ret != NULL) {
            for(int i = 0; i < ret->length(); i++, queue.remove()) {
                ret->set(i, queue.front()->value);
            }
        } else {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create return array ..."); 
        }

        return ret;
    }

    ~BTree()
    {
        clear();
    }

};

}



#endif