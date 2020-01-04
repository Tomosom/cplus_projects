#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

int myatoi(const char *str)
{
	if(*str<'0' || *str >'9')
	//	cout<<"wrong arg!" <<endl;
		throw "wrong arg!";
	else
		return atoi(str);
}


int main(int argc, const char *argv[])
{
	
	try{

		int data = myatoi("d123ss56");
		cout<< data <<endl;
	}
	catch(const char* p)
	{
		cout << p<<endl;
	}
	return 0;
}
