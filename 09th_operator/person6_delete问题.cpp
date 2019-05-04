#include <iostream>
#include <string.h>
#include <unistd.h>
#include <string.h>
using namespace std;
class Person{
private:
    char *name;
    int age;
    char *work;
public:
    Person(){
        name = NULL;
        work = NULL;
    }

    Person(const char *name, int age, const char *work = "none"){
        cout<<"Person(char *, int), name = "<<name<<", age = "<<age<<", work = "<<work<<endl;
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        this->age = age;
        this->work = new char[strlen(work)+1];
        strcpy(this->work, work);
    }

    ~Person(){
        cout << "name = "<<name<<", age = "<<age<<", work = "<<work<<endl;

#if 0   //为什么delete两个没错误，delete一个有错误
        delete this->name;
        delete this->work;
#else
        delete this->name;
        //delete this->work;
#endif

    }
};

int main(void){
	Person p1("zhangsan", 10);
    Person p2;
    p2 = p1;    // 赋值操作值拷贝

    return 0;
}
