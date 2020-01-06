#include <stdio.h>

int& demo()
{
    int d = 0;
    
    printf("demo: d = %d\n", d);
    
    return d;
}

int& func()
{
    static int s = 0;
    
    printf("func: s = %d\n", s);
    
    return s;
}

int main(int argc, char* argv[])
{
    int& rd = demo();
    int& rs = func();
    
    printf("\n");
    printf("main: rd = %d\n", rd);
    printf("main: rs = %d\n", rs);
    printf("\n");
    
    rd = 10;
    rs = 11;
    
    demo();
    func();
    
    printf("\n");
    printf("main: rd = %d\n", rd);
    printf("main: rs = %d\n", rs);
    printf("\n");
    
    return 0;
}
