/*
 *           Object
 *        ^         ^
 *        |         |
 *      Tree ----> TreeNode
 * 
 */

#ifndef TREE_H
#define TREE_H

#include "tree_node.h"
#include "shared_pointer.h"

namespace DTLib {

template <typename T>
class Tree : public Object {
protected:
    TreeNode<T> *m_root;

public:
    Tree() { m_root = NULL; }
    virtual bool insert(TreeNode<T> *node) = 0;
    virtual bool insert(const T &value, TreeNode<T> *parent) = 0;
    virtual SharedPointer< Tree<T> > remove(const T &value) = 0;
    virtual SharedPointer< Tree<T> > remove(TreeNode<T> *node) = 0;
    virtual TreeNode<T> *find(const T &value) const = 0;
    virtual TreeNode<T> *find(TreeNode<T> *node) const = 0;
    virtual TreeNode<T> *root() const = 0; // 访问树的根节点

    // 获取树的属性
    virtual int degree() const = 0; // 获取树的度
    virtual int count() const = 0;  // 获取树的节点数
    virtual int height() const = 0; // 获取树的高度
    virtual void clear() = 0;       // 清空树中的元素
};


}

#endif