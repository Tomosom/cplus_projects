#include <iostream>

using namespace std;

class OS{
public:
    virtual void InstallOS_impl() = 0;

};

class LinuxOS:public OS{
public:
    virtual void InstallOS_impl(){
        cout<<"install linux os"<<endl;
    }

};

class WindowsOS:public OS{
public:
    virtual void InstallOS_impl(){
        cout<<"install windows os"<<endl;
    }

};
// 扩展一个操作系统
class UnixOS:public OS{
public:
    virtual void InstallOS_impl(){
        cout<<"install unix os"<<endl;
    }

};


class Computer{
public:
    virtual void printfInfo() = 0;
    virtual void InstallOS() = 0;
};

class MAC:public Computer{
public:
    virtual void printfInfo(){  cout<<"this is mac"<<endl;}
    void InstallOS(){
        printfInfo();
        impl->InstallOS_impl();
    }
    MAC(OS *impl){
        this->impl = impl;
    }

private:
    OS *impl;
};

class Lenovo:public Computer{
public:
    virtual void printfInfo(){  cout<<"this is lenovo"<<endl;}
    void InstallOS(){
        printfInfo();
        impl->InstallOS_impl();
    }
    Lenovo(OS *impl){
        this->impl = impl;
    }

private:
    OS *impl;

};




int main(){
    OS *os1 = new LinuxOS();
    OS *os2 = new WindowsOS();
    OS *os3 = new UnixOS();

    Computer *c1 = new MAC(os1);
    Computer *c2 = new Lenovo(os2);
    Computer *c3 = new Lenovo(os3);
    c1->InstallOS();
    c2->InstallOS();
    c3->InstallOS();

    return 0;
}