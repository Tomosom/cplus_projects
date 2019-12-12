#include <iostream>
#include "exception.h"
using namespace std;
using namespace DTLib;

int main(int argc, char **argv)
{

	try {
		THROW_EXCEPTION(ArithmetricException, "test");
	}
	
	catch(const ArithmetricException &e){
		cout << "catch(const ArithmetricException &e)" << endl;
		cout << e.message() << endl;
		cout << e.location() << endl;
	}		
	
	catch(const Exception &e){
		cout << "catch(const Exception &e)" << endl;
		cout << e.message() << endl;
		cout << e.location() << endl;
	}


	return 0;
	
}