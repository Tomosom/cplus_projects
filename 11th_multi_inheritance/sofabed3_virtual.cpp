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


};

class Sofa : virtual public Furniture{  //虚拟继承，父类中的成员地址共用
private:
    int a;
public:
    void WatchTV(void) { cout<<"watch tv"<<endl;    }

};

class Bed : virtual public Furniture{
private:
    int b;
public:
    void sleep(void) { cout<<"sleep"<<endl; }

};


class Sofabed : public Sofa, public Bed {

private:
    int c;


};

int main(int argc, char **argv){
    Sofabed s;
    s.WatchTV();
    s.sleep();

    s.set_weight(10);
    cout<<s.get_weight()<<endl;
//    s.Sofa::set_weight(12);
//    cout<<s.Sofa::get_weight()<<endl;
    return 0;
}

