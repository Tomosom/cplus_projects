#include <iostream>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

class MyException{
public:
    virtual void What(void) {cout<<"this is MyException"<<endl;}

};
class MySubException:public MyException{
public:
    void What(void) {cout<<"this is MySubException"<<endl;}

};

void C(int i) throw(int, double){   //扔出异常限制
    int a = 1;
    double b = 1.2;
    float c = 1.3;


    if(i == 0){
        cout<<"in c is ok"<<endl;
    } else if(i == 1) {
        throw a;
    } else if(i == 2) {
        throw b;
    } else if(i == 3){
        throw c;
    } else if(i == 4){
        throw MyException();
    } else if(i == 5){
        cout<<"hello"<<endl;
        throw MySubException();
    }
}

void B(int i){

    cout<<"call c ..."<<endl;
    C(i);
    cout<<"atter call c"<<endl;
}

void A(int i){
    try{

        B(i);
    }catch(int j){
        cout<<"catch int exception "<<j<<endl;
    }
    catch(double j){
        cout<<"catch double exception "<<j<<endl;
    }

    catch(MyException &e){
        e.What();
    }
    catch(...){
        cout<<"catch other exception "<<endl;
    }


}

int main(int argc, char **argv){
    int i;
    if(argc != 2){
        cout<<"usage : "<<endl;
        cout<<argv[0]<<" "<<"<0|1|2|3>"<<endl;
        return -1;
    }

    i = strtoul(argv[1], NULL, 0);

    A(i);


    return 0;
}
