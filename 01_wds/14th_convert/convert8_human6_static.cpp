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

class Guangximan : public Chineseman{
public:
    void eating(void) { cout<<"using chopsticks to eat, i come from Guangxi" << endl; }

};

void test_eating(Human &h){


    //指针转换不成功，返回NULL
    //引用转换不成功，程序奔溃
    //所以动态类型转换中，经常使用指针，不使用引用
#if 1
    Englishman &pe = dynamic_cast<Englishman &>(h);   //terminate called after throwing an instance of 'std::bad_cast'
    Chineseman &pc = dynamic_cast<Chineseman &>(h);
    Guangximan &pg = dynamic_cast<Guangximan &>(h);
#else
    Englishman &pe = reinterpret_cast<Englishman &>(h);
    Chineseman &pc = reinterpret_cast<Chineseman &>(h);
    Guangximan &pg = reinterpret_cast<Guangximan &>(h);


#endif
    h.eating();

}

int main(int argc, char **argv){
    Human h;
//    Englishman e;
//    Chineseman c;
    Guangximan g;

    // static_cast上行转换OK，下行转换错误

    Englishman *pe1 = static_cast<Englishman *>(&h);

    //Englishman *pe2 = static_cast<Englishman *>(&g);  //error

    Chineseman *pc = static_cast<Chineseman *>(&g);


    return 0;
}

