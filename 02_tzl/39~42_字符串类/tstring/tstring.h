#ifndef TSTRING_H
#define TSTRING_H

#include "object.h"

namespace DTLib{

class TString : public Object {
protected:
    char *m_str;
    int m_length;

    void init(const char *s);
    bool equal(const char *l, const char *r, int len) const;
public:
    TString();
    TString(const char *s);
    TString(const TString &s);
    TString(char c);
    int length() const;
    const char *str() const;

    /* 字符串类中的常用成员函数 */
    char &operator [] (int i); // 操作符重载函数，访问指定下标的字符
    char operator [] (int i) const;
    bool startWith(const char *s) const;    // 判断字符串是否以s开头
    bool startWith(const TString &s) const;
    bool endOf(const char *s) const;        // 判断字符串是否以s结束
    bool endOf(const TString &s) const;
    TString &insert(int i, const char *s);    // 在字符串的位置i处插入s
    TString &insert(int i, const TString s);
    TString &trim();          // 去掉字符串两端的空白

    /* 比较操作符重载函数 */
    bool operator == (const TString &s) const;
    bool operator == (const char *s) const;
    bool operator != (const TString &s) const;
    bool operator != (const char *s) const;
    bool operator > (const TString &s) const;
    bool operator > (const char *s) const;
    bool operator < (const TString &s) const;
    bool operator < (const char *s) const;
    bool operator >= (const TString &s) const;
    bool operator >= (const char *s) const;
    bool operator <= (const TString &s) const;
    bool operator <= (const char *s) const;
    /* 加法操作符重载函数 */
    TString operator + (const TString &s) const;
    TString operator + (const char *s) const;
    TString &operator += (const TString &s);
    TString &operator += (const char *s);
    /* 赋值操作符重载函数 */
    TString &operator = (const TString &s);
    TString &operator = (const char *s);
    TString &operator = (const char c);

    ~TString();

};
}

#endif