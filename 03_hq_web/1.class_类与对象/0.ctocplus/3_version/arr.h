#ifndef _ARR_H_
#define _ARR_H_

#include<stdio.h>

typedef struct arr
{
	int data[100];
	int tail;
	void (*add_tail)(struct arr* arr , int input);
	void (*show)(struct arr* arr);
}ARR;

void init_arr(ARR* arr);

#endif
