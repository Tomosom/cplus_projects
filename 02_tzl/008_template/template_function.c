#include <iostream>

using namespace std;

template <typename T>
void my_swap(T &a, T&b)
{
	T t = a;
	a = b;
	b = t;
}

int main(int argc, char **argv)
{
	int a = 2;
	int b = 1;
	
	my_swap(a, b);
	
	cout << a << " " << b <<endl;

	double c = 0.01;
	double d = 0.02;
	my_swap<double>(c, d);
	cout << c << " " << d <<endl;
	
	return 0;
}