#include <iostream>
#include "tstring.h"

using namespace std;
using namespace DTLib;

/* 字符串常规造作测试 */
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

/* 字符串常规造作测试 */
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

/* 数组访问操作符重载函数测试 */
void test_3()
{ 
    TString s = "Tao Jia Quan";
    for(int i = 0; i < s.length(); i++) {
        cout << s[i] << endl;
    }
}

/* startWith和endOf函数测试 */
void test_4()
{
    TString s = "Tao Jia Quan";
    
    cout << s.startWith("Tao") << endl;
    cout << s.endOf("Quan") << endl;
    // for(int i = 0; i < s.length(); i++) {
    //     cout << s[i] << endl;
    // }
}

/* 插入字符串函数insert测试 */
void test_5()
{
    TString s = "";
    
    s.insert(0, "Tao ");
    s.insert(4, "software");
    s.insert(4, "jia quan ");
    cout << s.str() << endl;
    cout << s.insert(4, "jia quan ").str() << endl;
}

/* trim函数测试 */
void test_6()
{
    TString s = "   abc    ";
    
    if (s.trim().insert(0, "Tao ").endOf("abc") && s.startWith("Tao")) { // 链式调用的操作
        cout << "[" << s.str() << "]" << endl;
    }
}

int main(int argc, char **argv)
{
    //test_1();
    //test_2();
    //test_3();
    //test_4();
    //test_5();
    test_6();

    return 0;
}
