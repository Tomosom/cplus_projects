#include <iostream>

using namespace std;

// 求前N个数相加
unsigned int sum(unsigned int n)
{
    if (n > 1) {
        return n + sum(n - 1);
    } else {
        return 1;
    }
}

// 求斐波那契数列
unsigned int fac(unsigned int n)
{
    if (n > 2) {
        return fac(n - 1) + fac(n - 2);
    }

    if (n == 1 || n == 2) {
        return 1;
    }
}

// 一条语句实现strlen的由来
unsigned int _strlen(const char *s)
{
#if 0

    if (*s != '\0') {
        return 1 + _strlen(s + 1);
    } else {
        return 0;
    }

#else

    return s ? (*s ? (1 + _strlen(s + 1)) : 0) : 0;

#endif
}

int main(int argc, char **argv)
{

    cout << sum(100) << endl;

    for(int i = 1; i <= 10; i++) {
        cout << i << ":" << fac(i) << endl;
    }

    cout << _strlen("tao") << endl;

    return 0;
}