#include <iostream>
#include <unistd.h>
using namespace std;

class Singleton;


class Singleton {
private:
    static Singleton *gInstance;
public:
    static Singleton *getInstance(){
        return gInstance;
    }
    void printInfo(){
        cout<<"this is singleton"<<endl;
    }

private:
    Singleton(){
        cout<<"Singleton()"<<endl;
    }
};

void *start_routine_thread1(void *arg){
    cout<<"this is thread1 ..."<<endl;
    Singleton *s2 = Singleton::getInstance();
    s2->printInfo();
    return NULL;
}
void *start_routine_thread2(void *arg){
    cout<<"this is thread1 ..."<<endl;
    Singleton *s2 = Singleton::getInstance();
    s2->printInfo();
    return NULL;
}

/* 饿汉模式：实例先生成 */
Singleton *Singleton::gInstance = new Singleton;

int main(){

    Singleton *s = Singleton::getInstance();
    s->printInfo();
    Singleton *s1 = Singleton::getInstance();
    s1->printInfo();
    Singleton *s2 = Singleton::getInstance();
    s2->printInfo();

//    Singleton *s3 = new Singleton;
//    Singleton s4;

    /*创建线程*/
    pthread_t thread1ID;
    pthread_t thread2ID;
    pthread_create(&thread1ID, NULL, start_routine_thread1, NULL);
    pthread_create(&thread2ID, NULL, start_routine_thread2, NULL);

    sleep(3);
    return 0;
}


