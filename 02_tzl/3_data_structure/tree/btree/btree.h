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

template <typename T>
class BTree : public Tree<T> {
public:
    // implementation
    bool insert(TreeNode<T> *node)
    {
        int ret = true;

        return ret;
    }
    bool insert(const T &value, TreeNode<T> *parent)
    {
        int ret = true;

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
    BTreeNode<T> *find(const T &value) const
    {
        return NULL;
    }
    BTreeNode<T> *find(TreeNode<T> *node) const
    {
        return NULL;
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