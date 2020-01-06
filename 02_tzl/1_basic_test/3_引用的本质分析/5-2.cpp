#include <stdio.h>

struct TRef
{
    char& r;
};

int main(int argc, char *argv[])
{ 
    char c = 'c';
    char& rc = c;
    TRef ref = { c };
    
    printf("sizeof(char&) = %d\n", sizeof(char&));
    printf("sizeof(rc) = %d\n", sizeof(rc));
    
    printf("sizeof(TRef) = %d\n", sizeof(TRef));
    printf("sizeof(ref.r) = %d\n", sizeof(ref.r));

    return 0;
}
