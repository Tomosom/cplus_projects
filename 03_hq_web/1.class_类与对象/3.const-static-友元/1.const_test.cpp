#include<stdio.h>

class A
{
	public:
		A(int a = 998,int data = 888):b(data)//仅此种方式初始化b
		{
			//b = 889;
			printf("A()-----------\n");

			this->a = a;

		}

		~A()
		{
			printf("~A()~~~~~~~~~~\n");


		}
		void show() const //const成员函数不能修改成员变量
		{
			//a++;
			printf("a=%d,b=%d\n",a,b);
		}
	private:
		int a;
		const int b;
};

int main(int argc, const char *argv[])
{
	A x(520);
	x.show();

	A y;
	y.show();

	A z(12,34);
	z.show();
	return 0;
}
