#include"arr.h"
static void add_tail(ARR* arr , int input);
static void show(ARR* arr);

void init_arr(ARR* arr)
{
	arr->tail = 0;
	arr->add_tail = add_tail;
	arr->show = show;
}

static void add_tail(ARR* arr , int input)
{
	arr->data[arr->tail] = input;
	arr->tail++;
}

static void show(ARR* arr)
{
	int i = 0;
	for(;i<arr->tail ; i++)
		printf("%4d",arr->data[i]);
	printf("\n");
}
