#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
class Person{
private:
    char *name;
    int age;
    char *work;
public:
	int SetName(char *name){
        this->name = name;
        return 0;
    }

 	int SetAge(int age){
        this->age = age;
        return 0;
    }   

 	int SetWork(char *work){
        this->work = work;
        return 0;
    }   

	void printf_info(void){
		printf("name : %s, age : %d, work : %s\n", name, age, work);
	}
};

int main(void){
#if 0
    Person persons[] = {
        {"xiaohong", 10, "student"},
        {"zhangsan", 13, "niumang"},
        {"lisi", 30, "teacher"},
        {"jiaquan", 23, "handsome"}, 
    };

    int i = 0;
    for(; i < 4; i++){
        persons[i].printf_info();
    }
#endif

	Person per;

	per.SetName("xiaoming");
	per.SetAge(20);
	per.SetWork("teacher");


	per.printf_info();
    return 0;
}



 