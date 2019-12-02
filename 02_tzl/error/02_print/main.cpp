#include <iostream>
#include "link_list.h"

using namespace std;

int main(int argc, char **argv)
{
    LinkList<int> list;
    for(int i = 0; i < 5; i++) {
        list.insert(i);
    }

    cout << "length " << list.length() << endl;

    for(int i = 0; i < list.length(); i++) {
/*
        int v = 0;
        list.get(i, v);
        cout << v << endl;
        */
        //cout << " : " << i << endl;
        cout << "main : " << list.get(i) << endl;
        //list.get(i);
    }
	return 0;

}