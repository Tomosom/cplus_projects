#include<stdio.h>
//#include<iostream.h>
class A
{
public:

	A() //默认构造函数
	{
		printf("contructed!!!!!!\n");
	}
	A(int data) //重载构造函数
	{
	
		a = data;
	}
	~A() //析钩函数，在对象销毁的时候调用（出栈区大括号的时候）
	{
		printf("dddddddddddd\n");
	}

	void setdata(int n);
	int getdata()
	{
		return a;
	}
private: //外部想要修改和查询，均不能实现 
	int a;
};

void A::setdata(int n)
{
	a = n;
}

int main(int argc, const char *argv[])
{
	
	A x(520); //构造函数传参
//	x.a = 12;
	printf("%d\n",x.getdata());
//
	x.setdata(998);
	printf("%d\n",x.getdata());
//	printf("%d\n",x.a);
//	cout<<x.a;
	return 0;
}
