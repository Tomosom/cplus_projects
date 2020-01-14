#ifndef GTREE_NODE_H
#define GTREE_NODE_H

#include "tree.h"
#include "link_list.h"

namespace DTLib {

template <typename T>
class GTreeNode : public TreeNode<T> {
protected:
    bool m_flag;

    GTreeNode(const GTreeNode<T>&);
    GTreeNode &operator = (const GTreeNode<T>&); // 不能被复制

    void *operator new (size_t size) throw() // 声明一个不抛出异常的函数
    {
        return Object::operator new(size);
    }

public:
    LinkList<GTreeNode<T> *> child;

    GTreeNode()
    {
        m_flag = false;
    }

    bool flag()
    {
        return m_flag;
    }

    static GTreeNode<T> *NewNode()
    {
        GTreeNode<T> *ret = new GTreeNode<T>();
        if (ret != NULL) {
            ret->m_flag = true;
        }
        return ret;
    }


};


}

#endif
