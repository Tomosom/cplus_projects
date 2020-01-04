#include<stdio.h>
#include<iostream>

using namespace std;

class Convert
{
public:
	Convert()
	{
		rate = 6.4;
	}
	~Convert()
	{
	}

	Convert(double rate)
	{
		this->rate = rate;
	}

	double operator()(double rmb) // 仿函数
	{
		return rate*rmb;
	}

private:
	double rate;
};

int main(int argc, const char *argv[])
{
	Convert toUS(6.4);
	cout << toUS(10) <<endl;
	cout << toUS(10) <<endl;
	cout << toUS(10) <<endl;
	cout << toUS(10) <<endl;
	cout << toUS(10) <<endl;
	
	Convert toENG(8.4);
	cout << toENG(10) << endl;
	cout << toENG(10) << endl;
	cout << toENG(10) << endl;
	cout << toENG(10) << endl;
	cout << toENG(10) << endl;
	cout << toENG(10) << endl;

	cout<< 12320 << endl;

	return 0;
}
