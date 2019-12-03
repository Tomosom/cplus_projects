#include <iostream>
#include "link_list.h"

using namespace std;
using namespace DTLib;


int main(int argc, char **argv)
{
    LinkList<int> list;
    for(int i = 0; i < 5; i++) {
        list.insert(i);
    }

    cout << "length " << list.length() << endl;

    for(int i = 0; i < list.length(); i++) {
        cout << "main : " << list.get(i) << endl;
    }
	return 0;

}