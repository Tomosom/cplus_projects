//源代码拿不到，因为是库，又看中里边的功能，可使用继承
#include<iostream>
using namespace std;

class A{
public:
	A(){}
	~A(){}

	void showx(void)
	{
		cout<<"xxxxxxxx"<<endl;
	}
private:
	void showz(void)
	{
		cout<<"zzzzzz"<<endl;
	}
};


//class AX:private A{ //只能用public
class AX:public A{
public:
	void showy(void)
	{
		cout<< "yyyyyy"<<endl;
	}
};


int main(int argc, const char *argv[])
{
	A a;
	a.showx();

	AX b;
	b.showx();
	//b.showz();
	b.showy();


	return 0;
}
