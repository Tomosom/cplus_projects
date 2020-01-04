#include<iostream>

using namespace std;

class A{
public:
	A(){}
	virtual ~A() //虚析钩函数，防止内存泄漏，更安全
	{
		cout<<"A~~~~"<<endl;
	}

	virtual void show()
	{
		cout<<"AAAAAAA"<<endl;
	}
};

class AX:public A{
public:
	~AX()
	{
		cout<<"AX~~~~"<<endl;
	}
	void show()
	{
		cout<<"BBBBBBB"<<endl;
	}
};

int main(int argc, const char *argv[])
{

	//AX a;
	
	//AX* q = new AX;
	//delete q;
	
	A* q = new AX; //因定义了虚析钩函数
	delete q; //所以对象销毁时,调用了派生类的析钩函数

#if 0
	AX a;
	AX *q = &a;
	A  *p = &a;

	q->show();
	p->show();
#endif
	return 0;
}
