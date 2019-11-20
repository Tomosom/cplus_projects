#include <iostream>
#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include <unistd.h>

using namespace std;
class Person{
private:
    static int cnt;
    char *name;
    int age;
    char *work;
public:
    Person(){
        name = NULL;
        work = NULL;
        cnt++;
    }
    Person(const char *name){
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        this->work = NULL;
        cnt++;
    }

    Person(const char *name, int age, const char *work = "none"){
        cout<<"Person(char *, int), name = "<<name<<", age = "<<age<<", work = "<<work<<endl;
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        this->age = age;
        this->work = new char[strlen(work)+1];
        strcpy(this->work, work);
        cnt++;
    }

    Person(Person &per){
        cout<<"Person(Person &)"<<endl;
        this->name = new char[strlen(name)+1];
        strcpy(this->name, per.name);
        this->age = per.age;
        this->work = new char[strlen(work)+1];
        strcpy(this->work, per.work);
        cnt++;
    }

    ~Person(){
        cout << "~Person()" << endl;
        if(this->name) {
            cout << "name = "<<name<<endl;
            delete this->name;
        }
        if(this->work) {
            cout << "work = "<<work<<endl;
            delete this->work;
        }

    }

    static int Getcnt(){ return cnt; }

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

int Person::cnt = 0;

int main(void){
	Person person1;
	Person person2;
    Person person3;
	Person person4;

    cout << "person number = "<<Person::Getcnt()<<endl;

    return 0;
}
