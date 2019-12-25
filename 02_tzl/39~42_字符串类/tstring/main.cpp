#include <iostream>
#include "tstring.h"

using namespace std;
using namespace DTLib;

void test_1()
{
    cout << "test_1() begin ..." << endl;

    TString s;
    s = 'D';
    cout << s.str() << endl;
    cout << s.length() << endl;
    cout << (s == 'D') << endl;
    cout << (s > "CCC") << endl;

    s += "Tao jia";
    cout << s.str() << endl;
    cout << s.length() << endl;
    cout << (s == "DTao jia") << endl;

    cout << "test_1() end ..." << endl;
}

void test_2()
{
    cout << "test_2() begin ..." << endl;

    TString a[] = {"e", "d", "c", "b", "a"};
    TString min = a[0];
    
    for(int i = 0; i < 5; i++) {
        if (min > a[i]) {
            min = a[i];
        }
    }

    cout << "min = " << min.str() << endl;

    cout << "test_2() end ..." << endl;
}

int main(int argc, char **argv)
{
    test_1();
    test_2();
    return 0;
}
