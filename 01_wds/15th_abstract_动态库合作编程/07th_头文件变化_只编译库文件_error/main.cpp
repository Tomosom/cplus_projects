#include "Chinese.h"
#include "Englishman.h"
//#include "Human.h"
void test_eating(Human *h){
    h->eating();
}

int main(int argc, char **argv){
    Englishman e("Bill", 10, "ameri");
    Chinese c;

    e.setName("tom");
    c.setName("nancy");

    cout<<e.getName()<<endl;
    cout<<c.getName()<<endl;


    Human *h[2] = {&e, &c};
    int i;
    for(i = 0; i<2; i++){
        test_eating(h[i]);
    }


    return 0;
}

