#include <iostream>
#include "btree_node.h"
#include "tstring.h"

using namespace std;
using namespace DTLib;

#if 1
// 测试所需公用函数
template <typename T>
BTreeNode<T> *createTree()
{
    static BTreeNode<int> ns[9];

    for (int i = 0; i < 9; i++) {
        ns[i].value = i;
        ns[i].parent = NULL;
        ns[i].left = NULL;
        ns[i].right = NULL;
    }

    ns[0].left = &ns[1];
    ns[0].right = &ns[2];
    ns[1].parent = &ns[0];
    ns[2].parent = &ns[0];

    ns[1].left = &ns[3];
    ns[1].right = NULL;
    ns[3].parent = &ns[1];

    ns[2].left = &ns[4];
    ns[2].right = &ns[5];
    ns[4].parent = &ns[2];
    ns[5].parent = &ns[2];
    
    ns[3].left = NULL;
    ns[3].right = &ns[6];
    ns[6].parent = &ns[3];

    ns[4].left = &ns[7];
    ns[4].right = NULL;
    ns[7].parent = &ns[4];

    ns[5].left = &ns[8];
    ns[5].right = NULL;
    ns[8].parent = &ns[5];
    
    return ns;
}

template <typename T>
void printInOrder(BTreeNode<T> *node)
{
    if (node != NULL) {
        printInOrder(node->left);
        cout << node->value << " ";
        printInOrder(node->right);
    }
}

#endif

/*
 * question 1:
 * - 单度节点删除
 *      编写一个函数用于删除二叉树中的所有单度节点
 *      要求：节点删除后，其唯一的子节点代替它的位置
 * 
 *  思路：递归实现
 *  定义功能：delOdd1(node) ---> 二叉树中包含指向父节点的指针
 *      删除node为根节点的二叉树中的单度节点
 * 
 *               | return;                          node == NULL
 *               |
 *               | (伪码描述)
 *               | parent = node->parent;           degree == 1
 * delOdd1(node) | parent->child = node->child;
 *               | node->child->parent = parent;
 *               | delOdd1(node->child);
 *               |
 *               | delOdd1(node->left);             degree == 0 or degree == 2
 *               | delOdd1(node->right);
 */
template <typename T>
BTreeNode<T> *delOdd1(BTreeNode<T> *node)
{
    BTreeNode<T> *ret = NULL;
    if (node != NULL) {
        if (((node->left != NULL) && (node->right == NULL)) ||
            ((node->left == NULL) && (node->right != NULL)) ) {
            BTreeNode<T> *parent = dynamic_cast<BTreeNode<T>*>(node->parent);
            BTreeNode<T> *node_child = (node->left != NULL) ? node->left : node->right;

            if(parent != NULL) {
                BTreeNode<T> *&parent_child = (parent->left == node) ? parent->left : parent->right;
                parent_child = node_child;
                node_child->parent = parent;
            } else {
                node_child->parent = NULL;
            }

            if (node->flag()) { // 若是堆空间创建的
                delete node;
            }

            ret = delOdd1(node_child);
        } else {
            delOdd1(node->left);
            delOdd1(node->right);
            ret = node;
        }
    }

    return ret;
}



int main(int argc, char **argv)
{
    BTreeNode<int> *ns = createTree<int>();

    printInOrder(ns);

    cout << endl;

    ns = delOdd1(ns);

    printInOrder(ns);

    cout << endl;

    int a[] = {6, 7, 8};
    for (int i = 0; i < 3; i++) {
        TreeNode<int> *n = ns +a[i];
        while(n != NULL) {
            cout << n->value << " ";
            n = n->parent;
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
