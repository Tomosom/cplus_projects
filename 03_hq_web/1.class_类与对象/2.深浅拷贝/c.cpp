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

//	private:
		char *p;
};


int main(int argc, const char *argv[])
{
	A x;
	A y = x;
	
	printf("%s\n",y.p);

	return 0;
}













