#include "Human.h"
#include <string.h>
//#include <stdlib.h>
void Human::setName(const char *name){
    //this->name = (char *)malloc(sizeof(name));
    this->name = new char[sizeof(name)];
    strcpy(this->name, name);
}

char *Human::getName(void){
    return this->name;
}
