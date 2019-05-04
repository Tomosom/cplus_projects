#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Point {

private:
    int x;
    int y;

public:
    Point() {
        cout<<"Point()"<<endl;
    }
    Point(int x, int y) : x(x), y(y) {
        cout<<"Point(int x, int y)"<<endl;
    }

    Point(const Point &p) {
        cout<<"Point(const Point &p)"<<endl;
        x = p.x;
        y = p.y;
    }

    ~Point(){
        cout<<"~Point()"<<endl;
    }

    int getx(){ return x;   }
    int gety(){ return y;   }
    void setx(int x){ this->x = x; }
    void sety(int y){ this->y = y; }

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
    cout<<"begin"<<endl;
    ++p1;
    cout<<"-------"<<endl;
    p1++;
    cout<<"end"<<endl;


    return 0;
}


