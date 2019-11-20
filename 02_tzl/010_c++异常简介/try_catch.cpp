#include <iostream>

using namespace std;

double divide(double a, double b)
{
	const double delta = 0.000000000000001;
	double ret = 0;
	
	/*	判断b是否为零，浮点数最好不要用 b == 0 的方式来比较， 因为浮点数的表示其实是不精确的，直接和零
		比较得出的结果也许是有问题的 */
	if(!((-delta < b) && (b < delta))) {
		ret = a / b;
	} else {
		throw 0; /* 可以理解为异常地返回一个值 */
	}
	
	return ret;
}

void Demo1()
{
	try{
		throw 'c';
	}
	
	catch (int i) {
		cout << "catch(int i)" << endl;
	}
	catch (double d) {
		cout << "catch(double d)" << endl;
	}
	catch (char c) {
		cout << "catch(char c)" << endl;
	}	
}

void Demo2()
{
		throw "hello girl";
}

int main(int argc, char **argv)
{
	cout << "main() begin" << endl;
	try {
		int c = divide(1, 0);
		
		cout << "c = " << c << endl;
	}
	catch(...) {
		cout << "divided by zero" << endl;
	}
	
	Demo1();
	
	try {
		Demo2();
	}
	catch(char *c) {
		cout << "catch(char *c)" << endl;
	}
	catch(const char *cc) {
		cout << "catch(const char *cc) " << cc << endl;
	}	
	catch(...) {
		cout << "catch(...)" << endl;
	}
	
	cout << "main() end" << endl;
	
	return 0;
}