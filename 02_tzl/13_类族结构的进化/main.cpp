#include <iostream>
#include "object.h"
#include "smart_point.h"
#include "exception.h"

using namespace std;
using namespace DTLib;

class Test : public Object {
	
	
	
};

int main(int argc, char **argv)
{
	ArithmetricException *e = new ArithmetricException();
	delete e;
	
	//SmartPointer<int> *sp = new SmartPointer<int>;
	//delete sp;
	
	//Test *t = new Test;
	//delete t;
	
	
	return 0;
	
}