#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;
class Person{
private:
    int count;  //引用计数
public:
    void incStrong(){count++;}
    void decStrong(){count--;}
    int getStrongCount(){
        return count;
    }


    Person() : count(0){
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

//    int getStrongCount(){
//            return p->getStrongCount();
//    }


    SmartPoint():p(0) {
        cout<<"SmartPoint()"<<endl;
    }

    SmartPoint(Person *p){
        cout<<"SmartPoint(Person *p)"<<endl;
        this->p = p;
        this->p->incStrong();   //引用计数加一
    }

    SmartPoint(const SmartPoint &sp){ //拷贝构造函数
        cout<<"SmartPoint(SmartPoint &sp)"<<endl;
        this->p = sp.p;
        this->p->incStrong();   //引用计数加一
    }

    ~SmartPoint(){
        cout<<"~SmartPoint()"<<endl;

        if(p){
            p->decStrong();
            if(p->getStrongCount() == 0){
                delete p;
                p = NULL;
            }

        }
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

    cout<<"in call test_func: "<<sp->getStrongCount()<<endl;


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

    cout<<"before call test_func: "<<other->getStrongCount()<<endl;

    for(i = 0; i < 2; i++){
        test_func(other);
        cout<<"after call test_func: "<<other->getStrongCount()<<endl;
    }



    return 0;
}
