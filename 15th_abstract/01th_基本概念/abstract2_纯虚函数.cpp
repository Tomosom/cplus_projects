#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

// 虚函数机制
// 静态联编：非虚函数在编译时就确定好了调用哪一个
// 动态联编：在运行时确定调用哪一个
//           对象里有指针，指向虚函数表
//           通过指针，找到表，调用虚函数


class Human {       //抽象类
private:
    int a;


public:
    virtual void eating(void) = 0;
    virtual void wearing(void) = 0;
    virtual void driving(void) = 0;

    virtual ~Human() { cout<<"~Human()"<<endl; }
    virtual Human *test(void) {cout<<"Human's test"<<endl; return this;}

};

class Englishman : public Human{

public:
    void eating(void) { cout<<"using knife to eat" << endl; }
    void wearing(void){cout<<"wear english style"<<endl;}
    void driving(void){cout<<"drive english car"<<endl;}

    virtual ~Englishman(){ cout<<"~Englishman()"<<endl     ; }
    virtual Englishman *test(void) {cout<<"Englishman's test"<<endl; return this;}


};

class Chineseman : public Human{    //由于有纯虚函数未实现，所以仍然是一个抽象类

public:
    void eating(void) { cout<<"using chopsticks to eat" << endl; }
    void wearing(void){cout<<"wear chinese style"<<endl;}
    //void driving(void){cout<<"drive chinese car"<<endl;}
    virtual ~Chineseman(){ cout<<"~Chineseman()"     <<endl; }
    virtual Chineseman *test(void) {cout<<"Chineseman's test"<<endl; return this;}

};

class Guangximan : public Chineseman{

public:
    void driving(void){cout<<"drive guangxi car"<<endl;}

};


void test_eating(Human &h){

    h.eating();

}

void test_return(Human &h){

    h.test();

}

int main(int argc, char **argv){
    //Human h;
    Englishman e;
    //Chineseman c;
    Guangximan g;

    //test_return(h);
    test_return(e);
    //test_return(c);
    test_eating(g);

    return 0;
}

