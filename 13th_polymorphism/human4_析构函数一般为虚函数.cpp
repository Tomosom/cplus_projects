#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

// 虚函数机制
// 静态联编：非虚函数在编译时就确定好了调用哪一个
// 动态联编：在运行时确定调用哪一个
//           对象里有指针，指向虚函数表
//           通过指针，找到表，调用虚函数


class Human {
private:
    int a;


public:
    virtual void eating(void){cout<<"using hand to eat" << endl;}

    ~Human() { cout<<"~Human()"<<endl; }


};

class Englishman : public Human{

public:
    void eating(void) { cout<<"using knife to eat" << endl; }

    ~Englishman(){ cout<<"~Englishman()"     ; }


};

class Chineseman : public Human{

public:
    void eating(void) { cout<<"using chopsticks to eat" << endl; }
    ~Chineseman(){ cout<<"~Chineseman()"     ; }

};

void test_eating(Human &h){

    h.eating();

}

int main(int argc, char **argv){
    Human *h = new Human;
    Englishman *e = new Englishman;
    Chineseman *c = new Chineseman;

    Human *p[3] = { h, e, c };
    int i;
    for(i = 0; i<3; i++){
        p[i]->eating();
        delete p[i];
    }

    return 0;
}

