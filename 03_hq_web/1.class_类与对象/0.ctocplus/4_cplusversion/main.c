#include"arr.h"


int main(int argc, const char *argv[])
{
	ARR arr;
	int n=10;
	while( n-- )
		arr.add_tail(n);
	arr.show();
	return 0;
}
