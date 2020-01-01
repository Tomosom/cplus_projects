#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// 打印出移动的步数
void HanoiTower(int n, char a, char b, char c) // a==>src, b==>middle c==>dest
{
    if (n == 1) {
        cout << a << "-->" << c << endl;
    } else {
        HanoiTower(n - 1, a, c, b);
        HanoiTower(1, a, b, c);
        HanoiTower(n - 1, b, a, c);
    }
}

// 常规递归的方法计算移动步数
long long count_HanoiTower_1(int n) // a==>src, b==>middle c==>dest
{
    long long i = 0;

    if (n == 1) {
        //cout << a << "-->" << c << endl;
        return 1;
    } else {
        i += count_HanoiTower_1(n - 1);
        i += 1;
        i += count_HanoiTower_1(n - 1);
    }

    return i;
}

// 递归+动态规划
long long RESULT[1000] = {0};

long long count_HanoiTower_2(int n) // a==>src, b==>middle c==>dest
{
    if (n == 1) {
        RESULT[n] = 1; 
    } else {
        //cout << "^_^ : " << n << endl;
        RESULT[n] = RESULT[n] ? RESULT[n] : (2 * count_HanoiTower_2(n - 1) + 1);
    }

    return RESULT[n];
}

int main(int argc, char **argv)
{
    //HanoiTower(3, 'a', 'b', 'c');

    clock_t begin, end;

    int i;
    long long ret;

    while(1) {
        cin >> i;

        if (i <= 0) {
            return 0;
        }

        begin = clock();
        ret = count_HanoiTower_2(i);
        end = clock();
        cout << i << " : " << ret << endl;
        cout << "time : " << end - begin << "ms" << endl;
    }

    return 0;
}