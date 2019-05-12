#ifndef __CHINESE_H__
#define __CHINESE_H__

#include <iostream>
#include <string.h>
#include <unistd.h>

#include "Human.h"  //¿ÉÊ¡ÂÔ£¿

using namespace std;


class Chinese:public Human{
private:


public:


    void eating(void);
    void wearing(void);
    void driving(void);
    Chinese();
    virtual ~Chinese(){cout<<"~Chinese()"<<endl;}

};

#endif

