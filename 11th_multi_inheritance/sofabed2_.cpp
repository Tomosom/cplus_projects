#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Sofa {
private:
    int weight;

public:
    void WatchTV(void) { cout<<"watch tv"<<endl;    }

    void set_weight(int weight){
        this->weight = weight;
    }

    int get_weight(void) const{
        return this->weight;
    }

};

class Bed {
private:
    int weight;

public:
    void sleep(void) { cout<<"sleep"<<endl; }

    void set_weight(int weight){
        this->weight = weight;
    }

    int get_weight(void) const{
        return this->weight;
    }


};


class Sofabed : public Sofa, public Bed {

};

int main(int argc, char **argv){
    Sofabed s;
    s.WatchTV();
    s.sleep();

    //s.set_weight(10);   /* error, 有二义性 */
    s.Sofa::set_weight(12);
    cout<<s.Sofa::get_weight()<<endl;
    return 0;
}

