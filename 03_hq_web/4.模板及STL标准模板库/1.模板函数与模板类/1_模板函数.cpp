#include<iostream>
using namespace std;

template<typename XXX> //模板函数
XXX add(XXX a, XXX b)
{
	return a+b;
}


int main(int argc, const char *argv[])
{
	int a = 1,b = 3;
	double c = 2.3, d = 5.4;
	cout<<a<<"+"<<b<<"="<<add(a,b)<<endl;
	cout<<c<<"+"<<d<<"="<<add(c,d)<<endl;
	return 0;
}
