/*
 *           Object
 *        ^         ^
 *        |         |
 *      Tree ----> TreeNode
 *        ^           ^
 *        |           |
 *     GTree -----> GTreeNode 
 */

#ifndef GTREE_H
#define GTREE_H

#include "tree.h"
#include "gtree_node.h"

namespace DTLib {

template <typename T>
class GTree : public Tree<T> {
    // implementation
protected:
    GTreeNode<T> *find(GTreeNode<T> *node, const T &value) const
    {
        GTreeNode<T> *ret  = NULL;

        if (node != NULL) {
            if (node->value == value) {
                return node;
            } else {
                for (node->child.move(0); !node->child.end() && (ret == NULL); node->child.next()) {
                    ret = find(node->child.current(), value);
                }
            }
        }

        return ret;
    }

    GTreeNode<T> *find(GTreeNode<T> *node, const GTreeNode<T> *obj) const
    {
        GTreeNode<T> *ret  = NULL;

        if (node == obj) {
            return node;
        } else {
            if (node != NULL) {
                for (node->child.move(0); !node->child.end() && (ret ==NULL); node->child.next()) {
                    ret = find(node->child.current(), obj);
                }
            }
        }

        return ret;
    }

public:
    bool insert(TreeNode<T> *node) // 插入新节点
    {
        bool ret = true;
        
        return ret;
    }
    bool insert(const T &value, TreeNode<T> *parent) // 插入数据元素
    {
        bool ret = true;
        
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

    GTreeNode<T> *find(const T &value) const // 以值的方式查找
    {
        return find(root(), value);
    }
    GTreeNode<T> *find(TreeNode<T> *node) const // 以节点的方式查找
    {
        return find(root(), dynamic_cast<GTreeNode<T> *>(node));
    }
    
    GTreeNode<T> *root() const // 访问树的根节点
    {
        return dynamic_cast<GTreeNode<T>*>(this->m_root);
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

    ~GTree()
    {
        clear();
    }

};

}


#endif
