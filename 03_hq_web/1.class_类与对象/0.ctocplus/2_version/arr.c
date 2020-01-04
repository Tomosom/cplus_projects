#include"arr.h"

void init_arr(ARR* arr)
{
//	arr->data[100] = {0};
	arr->tail = 0;
}

void add_tail(ARR* arr , int input)
{
	arr->data[arr->tail] = input;
	arr->tail++;
}

void show(ARR* arr)
{
	int i = 0;
	for(;i<arr->tail ; i++)
		printf("%4d",arr->data[i]);
	printf("\n");
}
