#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Point {

private:
    int x;
    int y;

public:
    Point() {}
    Point(int x, int y) : x(x), y(y) {}

//    int getx(){ return x;   }
//    int gety(){ return y;   }
//    void setx(int x){ this->x = x; }
//    void sety(int y){ this->y = y; }

    void print_info(){
        cout << "x = "<<x<<", y = "<<y<<"\n";
    }

    friend Point add(Point &p1, Point &p2);

};


Point add(Point &p1, Point &p2){
    Point n;
    n.x = p1.x+p2.x;
    n.y = p1.y+p2.y;
    return n;
}


int main(int argc, char **argv){

    Point p1(1, 2);
    Point p2(2, 3);

    Point sum = add(p1, p2);
    sum.print_info();
    return 0;
}


