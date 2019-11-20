#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;
class Person{
private:

public:
    Person(){
        cout << "Person()" << endl;
    }

    ~Person(){
        cout << "~Person()" << endl;
    }

	void printf_info(void){
		cout<<"just a simple test"<<endl;
	}
};

void test_func(void){
//    Person *p = new Person();
//    p->printf_info();
    Person p;
    p.printf_info();


}

int main(void){
	int i;
    for(i = 0; i < 2; i++){
        test_func();
    }

    return 0;
}
