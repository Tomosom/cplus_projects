#ifndef TREE_NODE_H
#define TREE_NODE_H

#include "object.h"

namespace DTLib {

// 用来描述树里面的节点
template <typename T>
class TreeNode : public Object {
public:
    T value;
    TreeNode<T> *parent; // 指向父节点的指针

    TreeNode()
    {
        parent = NULL;
    }

    virtual ~TreeNode() = 0;
};

// 可以在头文件中定义抽象类的析构函数
template <typename T>
TreeNode<T>::~TreeNode()
{
    
}

}

#endif