#include<iostream>

using namespace std;

class A{
public:
	A(){}
	~A(){}

	//void show()
	virtual void show()
	{
		cout<<"AAAAAAA"<<endl;
	}
};

class AX:public A{
public:
	void show()
	{
		cout<<"BBBBBBB"<<endl;
	}
};

int main(int argc, const char *argv[])
{
#if 0
	A a;
	a.show();
	AX b;
	b.show();
#endif

	AX a;
	AX *q = &a;
	A  *p = &a;

	q->show();
	p->show();

	return 0;
}
