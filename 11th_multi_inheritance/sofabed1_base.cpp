#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Sofa {
public:
    void WatchTV(void) { cout<<"watch tv"<<endl;    }

};

class Bed {
public:
    void sleep(void) { cout<<"sleep"<<endl; }


};


class Sofabed : public Sofa, public Bed {

};

int main(int argc, char **argv){
    Sofabed s;
    s.WatchTV();
    s.sleep();

    return 0;
}

