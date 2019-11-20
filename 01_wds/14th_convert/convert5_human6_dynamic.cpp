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

    virtual ~Human() { cout<<"~Human()"<<endl; }


};

class Englishman : public Human{

public:
    void eating(void) { cout<<"using knife to eat" << endl; }

    virtual ~Englishman(){ cout<<"~Englishman()"<<endl     ; }


};

class Chineseman : public Human{

public:
    void eating(void) { cout<<"using chopsticks to eat" << endl; }
    virtual ~Chineseman(){ cout<<"~Chineseman()"     <<endl; }

};

void test_eating(Human &h){

    Englishman *pe;
    Chineseman *pc;

    h.eating();

    // 想分辨这个人时英国人还是中国人
    // 分辨对象的类名
    if(pe = dynamic_cast<Englishman *>(&h)){        //动态类型装换，只能用在含有虚函数的类中
        cout<<"this human is Englishman"<<endl;
    }
    if(pc = dynamic_cast<Chineseman *>(&h)){
        cout<<"this human is Chineseman"<<endl;
    }

}

int main(int argc, char **argv){
    Human h;
    Englishman e;
    Chineseman c;

    test_eating(h);
    test_eating(e);
    test_eating(c);

    return 0;
}

