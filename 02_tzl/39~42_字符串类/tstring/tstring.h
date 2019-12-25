#ifndef TSTRING_H
#define TSTRING_H

#include "object.h"

namespace DTLib{

class TString : public Object {
protected:
    char *m_str;
    int m_length;

    void init(const char *s);

public:
    TString();
    TString(const char *s);
    TString(const TString &s);
    TString(char c);
    int length() const;
    const char *str() const;

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