#include <stdio.h>

int main(int argc, char **argv){
    double d = 100.1;
    int i = d;
    const char *str = "hello,girl\n";
    char *str2 = const_cast<char *>(str);   //È¥µôconstÊôĞÔ
    int *p  = reinterpret_cast<int *>(str2);

    printf("i = %d, str = 0x%x, p = 0x%x\n", i, reinterpret_cast<unsigned int *>(str2), reinterpret_cast<unsigned int *>(p));

    return 0;

}
