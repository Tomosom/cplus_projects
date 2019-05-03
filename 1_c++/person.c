#include <stdio.h>
//#include <stdlib.h>

struct person{
    char *name;
    int age;
    char *work;
    void (*printf_info)(struct person per);
};

void printf_info(struct person per){
    printf("name : %s, age : %d, work : %s\n", per.name, per.age, per.work);
}

int main(void){
    struct person persons[] = {
        {"xiaohong", 10, "student", printf_info},
        {"zhangsan", 13, "niumang", printf_info},
        {"lisi", 30, "teacher", printf_info},
        {"jiaquan", 23, "handsome", printf_info}, 
    };

    int i = 0;
    for(; i < 4; i++){
        persons[i].printf_info(persons[i]);
    }

    return 0;
}



