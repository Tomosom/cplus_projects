#include<iostream>

using namespace std;

class mem{
public:
	explicit mem(int size){ //必须时显示的构造函数
		data = new char[size];
		cout<<"ccccc"<<endl;
	}
	~mem()
	{
		delete[] data;
	}
private:
	char* data;
};

int main(int argc, const char *argv[])
{
	//mem a(100);	
	mem a = 100; //没有explicit之前,此句为mem a(100);的隐式转换
	return 0;
}
