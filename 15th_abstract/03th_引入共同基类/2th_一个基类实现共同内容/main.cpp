#include "Chinese.h"
#include "Englishman.h"


int main(int argc, char **argv){
    Englishman e;
    Chinese c;

    e.setName("tom");
    c.setName("nancy");

    cout<<e.getName()<<endl;
    cout<<c.getName()<<endl;


    e.eating();
    c.eating();


    return 0;
}

