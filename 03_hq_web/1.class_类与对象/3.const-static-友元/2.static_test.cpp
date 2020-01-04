#include<stdio.h>

class A{

	public:
		static void func(void)
		{
			printf("xxxxxxxxxx\n");
		}
		static const int data;
//		static int data;
};

const int A::data = 998;
//int A::data = 998;

int main(int argc, const char *argv[])
{
	A x;
	x.func();
	A::func();
	printf("data = %d\n",x.data);
	//A::data = 888;
	//printf("data = %d\n",x.data);


	return 0;
}



