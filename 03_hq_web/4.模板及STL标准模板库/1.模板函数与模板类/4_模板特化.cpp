#include<iostream>
using namespace std;

template<typename XXX> //模板函数
XXX add(XXX a, XXX b)
{
	cout<<"----XXX"<<endl;
	return a+b;
}


#if 1
template<> //特化函数
bool add(bool a, bool b)
{
	cout<<"----bool"<<endl;
	
	if(a && b)
		return true;
	return false;
}
#endif
int main(int argc, const char *argv[])
{
	int a = 1,b = 3;
	double c = 2.3, d = 5.4;
	cout<<a<<"+"<<b<<"="<<add(a,b)<<endl;
	cout<<c<<"+"<<d<<"="<<add(c,d)<<endl;
	cout<<add(true, false)<<endl;
	cout<<add(true, true)<<endl;
	return 0;
}
