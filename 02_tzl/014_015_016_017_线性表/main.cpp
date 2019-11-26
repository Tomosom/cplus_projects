#include <iostream>
#include "static_list.h"

using namespace std;
using namespace DTLib;

int main(int argc, char **argv)
{
	//SeqList<int> *s;
	StaticList<int, 5> l;
	
	for (int i = 0; i < l.capacity(); i++) {
		l.insert(0, i);
	}
	
	for (int i = 0; i < l.length(); i++) {
		cout << l[i] << endl;
	}
	
	l[0] *= l[0];
	for (int i = 0; i < l.length(); i++) {
		cout << l[i] << endl;
	}

	try {
		l[5] = 5;
	}
	catch(const Exception &e) {
		cout << e.message() << endl;
		cout << e.location() << endl;
	}

	return 0;
	
}