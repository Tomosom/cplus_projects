#include <iostream>

using namespace std;

template <typename T>
void my_swap(T &a, T&b)
{
	T t = a;
	a = b;
	b = t;
}

template <typename T>
class Op {
public:
	T process(T v)
	{
		return v * v;
	}
};

int main(int argc, char **argv)
{
	Op<int> opint;
	Op<double> opdouble;
	
	cout << opint.process(5) << endl;
	cout << opdouble.process(0.03) << endl;
	return 0;
}