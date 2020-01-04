#include<stdio.h>
#include<string.h>

class A
{
	public:
		A()
		{
			printf("A()\n");
			p = new char[10];
			strcpy(p,"hello");
		}
#if 1
		A(const A &x)//深拷贝
		{
			printf("A(const A &x)\n");
			p = new char[10];
			strcpy(p,x.p);
		}
#endif
		~A()
		{
			printf("~A()\n");
			delete[] p;
		}

		A &operator=(A &x) //使用引用连续赋值，且减少对象创建 
		{
			printf("operator=\n");
			p = new char[10];
			strcpy(p,x.p);
			return *this;
		}


//	private:
		char *p;
};


int main(int argc, const char *argv[])
{
	A x;
	A y = x;
	printf("%s\n",y.p);

	y = x; //若要实现此步深拷贝，必须使用赋值重载运算符

	return 0;
}













