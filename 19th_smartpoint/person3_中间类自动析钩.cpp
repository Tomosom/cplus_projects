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


class sp {
private:
    Person *p;

public:
    sp():p(0) {
        cout<<"sp()"<<endl;
    }

    sp(Person *other){
        cout<<"sp(Person *other)"<<endl;
        p = other;
    }

    ~sp(){
        cout<<"~sp()"<<endl;
        if(p)
            delete p;
    }

    Person *operator->(){
        return p;
    }

};

void test_func(void){

//    Person *p = new Person();
//    p->printf_info();
    //sp s = new Person();
    sp s(new Person());

    s->printf_info();
}

int main(void){
	int i;
    for(i = 0; i < 2; i++){
        test_func();
    }

    return 0;
}
