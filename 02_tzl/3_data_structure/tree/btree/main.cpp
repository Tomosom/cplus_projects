#include <iostream>
#include "btree.h"

using namespace std;
using namespace DTLib;

int main(int argc, char **argv)
{
    BTree<int> bt;
    BTreeNode<int> *n = NULL;

    bt.insert(1, NULL);

    n = bt.find(1);
    bt.insert(2, n);
    bt.insert(3, n);

    n = bt.find(2);
    bt.insert(4, n);
    bt.insert(5, n);

    n = bt.find(3);
    bt.insert(6, n);
    bt.insert(7, n);

    n = bt.find(4);
    bt.insert(8, n);
    bt.insert(9, n);

    n = bt.find(5);
    bt.insert(10, n);
    
    n = bt.find(6);
    bt.insert(11, n, LEFT);

    cout << "count : " << bt.count() << endl;
    cout << "height : " << bt.height() << endl;
    cout << "root : " << bt.degree() << endl;

    // remove test
    SharedPointer< Tree<int> > sp = bt.remove(3);

    // 从叶节点开始反向打印
    int a[] = {8, 9, 10, 11, 7};
    for(int i = 0; i < 5; i++) {
        //TreeNode<int> *node = bt.find(a[i]);
        TreeNode<int> *node = sp->find(a[i]);

        while(node) {
            cout << node->value << " ";
            node = node->parent;
        }

        cout << endl;
   
    }

    return 0;
}