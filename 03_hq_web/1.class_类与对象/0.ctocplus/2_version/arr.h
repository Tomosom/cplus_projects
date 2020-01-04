#ifndef _ARR_H_
#define _ARR_H_

#include<stdio.h>

typedef struct arr
{
	int data[100];
	int tail;
}ARR;

void init_arr(ARR* arr);
void add_tail(ARR* arr , int input);
void show(ARR* arr);

#endif
