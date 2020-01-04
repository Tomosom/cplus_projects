#include<iostream>
#include<typeinfo>
using namespace std;
class A{
};

class B:public A{
};
class C{
	virtual void show(void)
	{
		cout << "ccccc" << endl;
	}
};
class D{
	void show(void)
	{
		cout << "ddddd" << endl;
	}
};

int main(int argc, const char *argv[])
{
#if 0
	int ch = 10;
	char* p;
	p = reinterpret_cast<char*>(&ch);
#endif
#if 0
	const int a = 10;
	int* p = const_cast<int*>( &a );
#endif
#if 0
	//想把A当作B来使用
	A a;
	B& b = static_cast<B&>( a );
#endif
	
	try{
		C c;
		D& d = dynamic_cast<D&>( c );
	}
	catch(bad_cast e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
