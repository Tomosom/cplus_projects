#include"arr.h"


void ARR::addtail(int data)
{
	this->data[tail] = data; //this指针，修饰类自己的变量
	tail++;
}
void ARR::show()
{
	int i=0;
	for(;i<tail;i++)
		printf("%4d",data[i]);
	putchar(10);
}

