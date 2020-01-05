#include <iostream>
#include "gtree.h"

using namespace std;
using namespace DTLib;

int main()
{
    GTree<int> t;
    GTreeNode<int> tn;

    t.find(0);
    t.find(&tn);

    return 0;
}