#include <stdio.h>

int main(int argc, char **argv){
    double d = 100.1;
    int i = d;
    char *str = "hello,girl\n";
    int *p  = reinterpret_cast<int *>(str);

    printf("i = %d, str = 0x%x, p = 0x%x\n", i, reinterpret_cast<unsigned int *>(str), reinterpret_cast<unsigned int *>(p));

    return 0;

}
