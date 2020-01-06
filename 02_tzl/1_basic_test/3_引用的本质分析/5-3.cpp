#include <stdio.h>

struct TRef
{
    char* before;
    char& ref;
    char* after;
};

int main(int argc, char* argv[])
{
    char a = 'a';
    char& b = a;
    char c = 'c';

    TRef r = {&a, b, &c};

    printf("sizeof(r) = %d\n", sizeof(r));
    printf("sizeof(r.before) = %d\n", sizeof(r.before));
    printf("sizeof(r.after) = %d\n", sizeof(r.after));
    printf("&r.before = %p\n", &r.before);
    printf("&r.after = %p\n", &r.after);

    return 0;
}
