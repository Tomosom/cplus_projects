#include<stdio.h>
#include<iostream>
using namespace std;

int main(int argc, const char *argv[])
{
//	printf("input:");fflush(stdout);
	cout << "input:";

	char buf[100];
//	gets(buf);
	cin >> buf;

//	printf("%s\n",buf);
	cout << buf <<endl;

	cout << 12.25 <<endl; 
	cout << 10 << endl;
	cout << hex <<10<<endl; //以16进制打印

	return 0;
}
