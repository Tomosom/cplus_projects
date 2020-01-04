#include"arr.h"


int main(int argc, const char *argv[])
{
	ARR<int,50> arr;
	arr.add_tail(1);
	arr.add_tail(2);
	arr.add_tail(3);
	arr.add_tail(4);
	arr.show();
	
	ARR<double,100> arr1;
	arr1.add_tail(1.22);
	arr1.add_tail(222.32);
	arr1.add_tail(3.455);
	arr1.add_tail(4.213);
	arr1.show();
	
	
	return 0;
}
