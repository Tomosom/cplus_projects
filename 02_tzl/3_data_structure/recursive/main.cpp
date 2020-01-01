#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

void permutation(char *s, char *e)
{
    if (*s == '\0') {
        cout << e << endl;
    } else {
        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            if ((i == 0) || (s[0] != s[i])) {
                swap(s[0], s[i]);
                permutation(s + 1, e);
                swap(s[0], s[i]);
            }
        }
    }
}

void swap_test() 
{
    char ch[10] = "hello";

    swap(ch[0], ch[2]);

    cout << ch << endl;
}

int main(int argc, char **argv)
{
    char s[] = "cbc";

    permutation(s, s);
    
    //swap_test();
    
    return 0;
}