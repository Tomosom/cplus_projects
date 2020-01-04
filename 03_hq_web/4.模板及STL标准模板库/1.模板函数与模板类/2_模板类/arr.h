#pragma once
#include<iostream>
using namespace std;
template <typename XXX>
class ARR
{
	public:
		ARR():tail(0){
		}
		
		void add_tail(XXX data);
		void show();
	private:
		XXX data[100];
		int tail;
};

template <typename XXX>
void ARR<XXX>::add_tail(XXX data)
{
	this->data[tail] = data; //this指针，修饰类自己的变量
	tail++;
}
template <typename XXX>
void ARR<XXX>::show()
{
	int i=0;
	for(;i<tail;i++)
		cout<< data[i] <<" ";
	cout<<endl;
}

