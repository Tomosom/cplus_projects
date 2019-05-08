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

};

class Englishman : public Human{

public:
    void eating(void) { cout<<"using knife to eat" << endl; }

};

class Chineseman : public Human{

public:
    void eating(void) { cout<<"using chopsticks to eat" << endl; }

};

void test_eating(Human h){

    h.eating();

}

int main(int argc, char **argv){
    Human h;
    Englishman e;
    Chineseman c;

    test_eating(h);
    test_eating(e);
    test_eating(c);

    cout<<"sizeof(Human) = "<<sizeof(h)<<endl;
    cout<<"sizeof(Englishman) = "<<sizeof(e)<<endl;
    cout<<"sizeof(Chineseman) = "<<sizeof(c)<<endl;

    return 0;
}

