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
    friend Point operator+(Point &p1, Point &p2);
    friend Point operator++(Point &p, int a);
    friend Point operator++(Point &p);

};


Point add(Point &p1, Point &p2){
    Point n;
    n.x = p1.x+p2.x;
    n.y = p1.y+p2.y;
    return n;
}

Point operator+(Point &p1, Point &p2){
    cout << "operator+"<<endl;
    Point n;
    n.x = p1.x+p2.x;
    n.y = p1.y+p2.y;
    return n;
}

/* Point p1(1, 2); p++ ;*/
Point operator++(Point &p, int a){  //多出来的形参没有作用？
    cout<<"p++"<<endl;
    Point n;
    n = p;
    p.x++;
    p.y++;
    return n;
}

/* Point p1(1, 2); ++p ;*/
Point operator++(Point &p){
    cout<<"++p"<<endl;
    p.x++;
    p.y++;
    return p;
}

int main(int argc, char **argv){

    Point p1(1, 2);
    Point p2(2, 3);

    Point n = p1++;
    p1.print_info();
    n.print_info();

    Point m = ++p2;
    p2.print_info();
    m.print_info();

    return 0;
}


