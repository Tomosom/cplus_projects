#include <iostream>
#include "smart_point.h"

using namespace std;
using namespace DTLib;

class Test
{
public:
	Test()
	{
		cout << "Test()" << endl;
	}
	
	~Test()
	{
		cout << "~Test()" << endl;
	}	
	
};

int main(int argc, char **argv)
{
	SmartPointer<Test> sp = new Test();
	
	SmartPointer<Test> nsp;
	nsp = sp;
	
	//nsp++;
	
	cout << sp.isNull() << endl;
	cout << nsp.isNull() << endl;
	
	//Test *sp = new Test();
	
}