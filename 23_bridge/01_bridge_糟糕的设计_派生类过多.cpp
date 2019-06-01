#include <iostream>

using namespace std;

class OS{
public:
    virtual void Install() = 0;

};

class LinuxOS:public OS{
public:
    virtual void Install(){
        cout<<"install linux os"<<endl;
    }

};

class WindowsOS:public OS{
public:
    virtual void Install(){
        cout<<"install windows os"<<endl;
    }

};

class Computer{
public:
    virtual void printfInfo() = 0;
};

class MAC:public Computer{
public:
    virtual void printfInfo(){  cout<<"this is mac"<<endl;};
};
class MacWithLinux:public LinuxOS, public MAC{
public:
    void InstallOS(){
        printfInfo();
        Install();
    }
};
class MacWithWindows:public WindowsOS, public MAC{
public:
    void InstallOS(){
        printfInfo();
        Install();
    }
};

class Lenovo:public Computer{
public:
    virtual void printfInfo(){  cout<<"this is lenovo"<<endl;};
};

class LenovoWithLinux:public LinuxOS, public Lenovo{
public:
    void InstallOS(){
        printfInfo();
        Install();
    }
};
class LenovoWithWindows:public WindowsOS, public Lenovo{
public:
    void InstallOS(){
        printfInfo();
        Install();
    }
};


int main(){
    MacWithLinux a;
    a.InstallOS();

    LenovoWithWindows b;
    b.InstallOS();
    return 0;
}