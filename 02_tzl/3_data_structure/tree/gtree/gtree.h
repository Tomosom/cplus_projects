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
public:
    virtual bool insert(TreeNode<T> *node)
    {
        bool ret = true;
        
        return ret;
    }
    virtual bool insert(const T &value, TreeNode<T> *parent)
    {
        bool ret = true;
        
        return ret;
    }
    virtual SharedPointer< Tree<T> > remove(const T &value)
    {
        return NULL;
    }
    virtual SharedPointer< Tree<T> > remove(TreeNode<T> *node)
    {
        return NULL;
    }
    virtual TreeNode<T> *find(const T &value) const
    {
        return NULL;
    }
    virtual TreeNode<T> *find(TreeNode<T> *node) const
    {
        return NULL;
    }
    virtual TreeNode<T> *root() const // 访问树的根节点
    {
        return dynamic_cast<GTreeNode<T>*>(this->m_root);
    }
    // 获取树的属性
    virtual int degree() const // 获取树的度
    {
        return 0;
    }
    virtual int count() const  // 获取树的节点数
    {
        return 0;
    }
    virtual int height() const // 获取树的高度
    {
        return 0;
    }
    virtual void clear()       // 清空树中的元素
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
