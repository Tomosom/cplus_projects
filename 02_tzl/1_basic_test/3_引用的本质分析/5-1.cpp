#include <stdio.h>

void Example()
{
    printf("Example:\n");
    
    int a = 4;
    const int& b = a;
    int* p = (int*)&b;
    
    //b = 5;
    
    *p = 5;
    
    printf("a = %d\n", a);
    printf("b = %d\n", b);
}

void Demo()
{
    printf("Demo:\n");
    
    const int& c = 1;
    int* p = (int*)&c;
    
    //c = 5;
    
    *p = 5;
    
    printf("c = %d\n", c);
}

int main(int argc, char *argv[])
{
    Example();
    
    printf("\n");
    
    Demo();

    return 0;
}
