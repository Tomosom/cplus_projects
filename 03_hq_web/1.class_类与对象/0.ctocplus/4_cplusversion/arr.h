#pragma once
#include<stdio.h>

class ARR
{
	public:
		//初始化表初始化法
		//ARR():tail(0){}
		ARR()
		{
			tail = 0;
		}
		
		void add_tail(int data);
		void show();
	private:
		int data[100];
		int tail;
};
