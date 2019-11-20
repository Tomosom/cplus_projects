#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Furniture {

private:
    int weight;

public:

    void set_weight(int weight){
        this->weight = weight;
    }

    int get_weight(void) const{
        return this->weight;
    }

    Furniture(){ cout << "Furniture()" <<endl; }

};


class Vertification3C {
public:
    Vertification3C() { cout<<"Vertification3C"<<endl;        }

};



class Sofa : virtual public Furniture, virtual public Vertification3C{  //虚拟继承，父类中的成员地址共用
private:
    int a;
public:
    void WatchTV(void) { cout<<"watch tv"<<endl;    }
    Sofa(){ cout << "Sofa()" <<endl; }


};

class Bed : virtual public Furniture, virtual public Vertification3C{
private:
    int b;
public:
    void sleep(void) { cout<<"sleep"<<endl; }

    Bed(){ cout << "Bed()" <<endl; }

};


class Sofabed : public Sofa, public Bed {

private:
    int c;

public:
    Sofabed(){ cout << "Sofabed()" <<endl; }
    Sofabed(const char *abc){ cout << "Sofabed(char *abc)" <<endl; }

};

class LeftRightCom {
public:
    LeftRightCom(){ cout << "LeftRightCom()" <<endl; }
    LeftRightCom(const char *abc){ cout << "LeftRightCom(char *abc)" <<endl; }

};

class Date {
public:
    Date(){ cout << "Date()" <<endl; }
    Date(const char *abc){ cout << "Date(char *abc)" <<endl; }


};


class Type {
public:
    Type(){ cout << "Type()" <<endl; }
    Type(const char *abc){ cout << "Type(char *abc)" <<endl; }

};


class LeftRightSoftbed : public Sofabed, virtual public LeftRightCom {

private:
    Date date;
    Type type;

public:
    LeftRightSoftbed(){         cout << "LeftRightSoftbed()" <<endl; }
    LeftRightSoftbed(const char *str1,         const char *str2, const char *str3) : Sofabed(str1), LeftRightCom(str2), date(str3){ cout << "LeftRightSoftbed()" <<endl; }

};

int main(int argc, char **argv){
    LeftRightSoftbed s("abc", "ss", "asf");

    return 0;
}

