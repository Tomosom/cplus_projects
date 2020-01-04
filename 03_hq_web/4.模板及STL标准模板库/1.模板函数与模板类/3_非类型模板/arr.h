#pragma once
#include<iostream>
using namespace std;
template <typename XXX, int SIZE>
class ARR
{
	public:
		ARR():tail(0){
		}
		
		void add_tail(XXX data);
		void show();
	private:
		XXX data[SIZE];
		int tail;
};

template <typename XXX, int SIZE>
void ARR<XXX,SIZE>::add_tail(XXX data)
{
	this->data[tail] = data; //this指针，修饰类自己的变量
	tail++;
}
template <typename XXX, int SIZE>
void ARR<XXX,SIZE>::show()
{
	int i=0;
	for(;i<tail;i++)
		cout<< data[i] <<" ";
	cout<<endl;
}

