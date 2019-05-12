#include "Englishman.h"


void Englishman::eating(void) {
    cout<<"using knife to eat" << endl;
}
void Englishman::wearing(void){
    cout<<"wear english style"<<endl;
}
void Englishman::driving(void){
    cout<<"drive english car"<<endl;
}


Englishman::Englishman(){

}
Englishman::Englishman(const char *name, int age, const char *address){
    setName(name);
    this->age = age;
    memset(this->adress, 0, 1000);
    strcpy(this->adress, address);
}


Englishman::~Englishman(){
    cout<<"~Englishman()"<<endl;
}

