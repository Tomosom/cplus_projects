#include <iostream>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

void C(int i){
    int a = 1;
    double b = 1.2;
    float c = 1.3;


    if(i == 0){
        cout<<"in c is ok"<<endl;
    } else if(i == 1) {
        throw a;
    } else if(i == 2) {
        throw b;
    } else {
        throw c;
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
    catch(float j){
        cout<<"catch float exception "<<j<<endl;
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
