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


class SmartPoint {
private:
    Person *p;

public:
    SmartPoint():p(0) {
        cout<<"SmartPoint()"<<endl;
    }

    SmartPoint(Person *p){
        cout<<"SmartPoint(Person *p)"<<endl;
        this->p = p;
    }

    SmartPoint(SmartPoint &sp){ //拷贝构造函数
        cout<<"SmartPoint(SmartPoint &sp)"<<endl;
        p = sp.p;
    }

    ~SmartPoint(){
        cout<<"~SmartPoint()"<<endl;
        if(p)
            delete p;
    }

    Person *operator->(){
        return p;
    }

};

void test_func(SmartPoint &other){
//void test_func(void){

//    SmartPoint sp = new Person();
//    SmartPoint sp(new Person());

    SmartPoint sp = other;

    sp->printf_info();
}

int main(void){
	int i;

    /* 相当于：
    * 1.    Person *p = new Person();
    * 2.    SmartPoint tmp(p);                  => SmartPoint(Person *p)
    * 3.
    * 3.1   SmartPoint other(tmp);              => SmartPoint(SmartPoint &sp)
    * 3.2   SmartPoint other( (Person *)tmp )   => SmartPoint(Person *p)
    */

    SmartPoint other = new Person();
    //SmartPoint other(new Person());

    for(i = 0; i < 2; i++){
        test_func(other);
    }

    return 0;
}
