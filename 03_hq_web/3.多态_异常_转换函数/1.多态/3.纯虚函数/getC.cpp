#include<iostream>
using namespace std;

class Shape{
public:
	virtual double Getc(void) = 0; //纯虚函数定义,该类不能生成对象
//	{
	
//	}

};

class Cir:public Shape{
public:
	Cir(double r):radius(r)
	{}

	double Getc(void)
	{
		return 2*3.14*radius;
	}

private:
	double radius;
};


class Tri:public Shape{
public:
	Tri(double e1, double e2, double e3):a(e1), b(e2), c(e3)
	{}

	double Getc(void)
	{
		return a+b+c;
	}

private:
	double a;
	double b;
	double c;
};

class Squ:public Shape{
public:
	Squ(double e)
	{
		this->e = e;
	}
	double Getc(void)
	{
		return 4*e;
	}
private:
	double e;
};


double totalc(Shape* arr[], int n)
{
	double sum = 0;
	for(int i = 0; i<n; i++)
	{
		sum += arr[i]->Getc();
	}
	return sum;
}


int main(int argc, const char *argv[])
{
	//Shape x; //因定义了纯虚函数,该对象的创建不成立
	Cir c1(2);
	Tri t(3,4,5);
	Squ s(4);
	Cir c2(6);

	Shape* arr[] = {&c1, &t, &s, &c2};

	cout << "totalc : " << totalc(arr, 4) <<endl;
	return 0;
}
