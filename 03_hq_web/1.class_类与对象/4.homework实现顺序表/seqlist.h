#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

class Seqlist
{
public:
	Seqlist();
	~Seqlist();

	bool Insert_data(int input, int locate);
	bool Delete_data(int key);
	bool Traverse_seq();
	int Incresize();

	int Getlast()
	{
		return last;
	}

private:
	int* data;
	int last;
	int increment;
	int arraysize;
};







