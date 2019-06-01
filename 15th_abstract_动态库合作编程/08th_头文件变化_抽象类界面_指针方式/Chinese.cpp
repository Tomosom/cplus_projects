#include "Chinese.h"


void Chinese::eating(void) {
    cout<<"using chopsticks to eat" << endl;
}
void Chinese::wearing(void){
    cout<<"wear chinese style"<<endl;
}
void Chinese::driving(void){
    cout<<"drive chinese car"<<endl;
}

Chinese::Chinese(){

}


Chinese::~Chinese(){
    cout<<"~Chinese()" <<endl;
}

Human *Create_Chinese(void){
    Chinese *c = new Chinese;
    return c;
}


