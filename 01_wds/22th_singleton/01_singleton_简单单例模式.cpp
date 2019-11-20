#include <iostream>

using namespace std;

class Singleton;

Singleton *gInstance;



class Singleton {
public:
    static Singleton *getInstance(){
        if(gInstance == NULL){
            gInstance = new Singleton;
        }
        return gInstance;
    }

    Singleton(){
        cout<<"Singleton()"<<endl;
    }

    void printInfo(){
        cout<<"this is singleton"<<endl;
    }
};

int main(){

    Singleton *s = Singleton::getInstance();
    s->printInfo();
    Singleton *s1 = Singleton::getInstance();
    s1->printInfo();
    Singleton *s2 = Singleton::getInstance();
    s2->printInfo();

    return 0;
}


