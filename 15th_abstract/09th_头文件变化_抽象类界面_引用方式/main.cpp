//#include "Chinese.h"
//#include "Englishman.h"
#include "Human.h"
void test_eating(Human *h){
    h->eating();
}

int main(int argc, char **argv){
    Human& e = Create_Englishman("Bill", 10, "ameri");
    Human& c = Create_Chinese();
//
//    e->setName("tom");
//    c->setName("nancy");
//
//    char *ch = NULL;
//
//    cout<<e->getName()<<endl;
//    cout<<c->getName()<<endl;
//    cout<<ch<<endl;

    Human *h[2] = {&e, &c};
    int i;
    for(i = 0; i<2; i++){
        test_eating(h[i]);
    }


    return 0;
}

