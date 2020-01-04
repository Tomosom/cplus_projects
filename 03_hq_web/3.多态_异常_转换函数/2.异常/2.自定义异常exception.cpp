#include<iostream>
#include<stdlib.h>
#include<stdio.h>

#include<exception>

using namespace std;


class argexception:public exception{ //继承exception类
public:
	const char* what() const throw()
	{
		return "arg err!";
	}
};

int myatoi(const char *str)
{
	if(*str<'0' || *str >'9')
	//	cout<<"wrong arg!" <<endl;
	//	throw "wrong arg!";
		throw argexception();
	else
		return atoi(str);
}


int main(int argc, const char *argv[])
{
	
	try{

		int data = myatoi("d123ss56");
		cout<< data <<endl;
	}
	//catch(const char* p)
	catch(argexception e)
	{
	//	cout << p<<endl;
		cout << e.what() <<endl;
	}
	return 0;
}
