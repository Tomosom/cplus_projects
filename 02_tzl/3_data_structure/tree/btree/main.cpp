#include <iostream>
#include "btree.h"

using namespace std;
using namespace DTLib;

int main(int argc, char **argv)
{
    BTree<int> bt;
    BTreeNode<int> btn;

    bt.find(1);
    bt.find(&btn);

    return 0;
}