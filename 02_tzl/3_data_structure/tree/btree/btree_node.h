#ifndef BTREE_NODE_H
#define BTREE_NODE_H

#include "tree.h"

namespace DTLib {

template <typename T>
class BTreeNode : public TreeNode<T> {
public:
    BTreeNode<T> *left;
    BTreeNode<T> *right;

    // factory pattern

    // ...

};




}


#endif