#include <iostream>

#ifndef offsetof
#define offsetof(TYPE, MEMBER) ((size_t)&((TYPE*)0)->MEMBER)
#endif

using namespace std;

class object {
	int oo;
};

struct ST : public object{
//struct ST{
	int i;
	int j;
	char c;
};

int main(int argc, char **argv)
{
	struct ST st;

	cout << "offsetof i : " << offsetof(struct ST, i) << endl;
	cout << "offsetof j : " << offsetof(struct ST, j) << endl;
	cout << "offsetof c : " << offsetof(struct ST, c) << endl;

	return 0;
}

