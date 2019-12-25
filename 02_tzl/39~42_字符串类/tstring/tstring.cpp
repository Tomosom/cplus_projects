#include <cstring>
#include <cstdlib>
#include "tstring.h"
#include "exception.h"

namespace DTLib {

void TString::init(const char *s)
{
    m_str = strdup(s);

    if (m_str) {
        m_length = strlen(m_str);
    } else {
        THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create tstring object ...");
    }

}

TString::TString()
{
    init("");
}

TString::TString(const char *s)
{
    init(s ? s : "");
}

TString::TString(const TString &s)
{
    init(s.m_str);
}

TString::TString(char c)
{
    char s[] = {c, '\0'};
    init(s);
}

int TString::length() const
{
    return m_length;
}

const char *TString::str() const
{
    return m_str;
}

/* 比较操作符重载函数 */
bool TString::operator == (const TString &s) const
{
    return (strcmp(m_str, s.m_str) == 0);
}
bool TString::operator == (const char *s) const
{
    return (strcmp(m_str, s ? s : "") == 0);
}
bool TString::operator != (const TString &s) const
{
    return !(*this == s);
}
bool TString::operator != (const char *s) const
{
    return !(*this == s ? s : "");
}
bool TString::operator > (const TString &s) const
{
    return (strcmp(m_str, s.m_str) > 0);
}
bool TString::operator > (const char *s) const
{
    return (strcmp(m_str, s ? s : "") > 0);
}
bool TString::operator < (const TString &s) const
{
    return (strcmp(m_str, s.m_str) < 0);
}
bool TString::operator < (const char *s) const
{
    return (strcmp(m_str, s ? s : "") < 0);
}
bool TString::operator >= (const TString &s) const
{
    return (strcmp(m_str, s.m_str) >= 0);
}
bool TString::operator >= (const char *s) const
{
    return (strcmp(m_str, s ? s : "") >= 0);
}
bool TString::operator <= (const TString &s) const
{
    return (strcmp(m_str, s.m_str) <= 0);
}
bool TString::operator <= (const char *s) const
{
    return (strcmp(m_str, s ? s : "") <= 0); 
}

/* 加法操作符重载函数 */
TString TString::operator + (const TString &s) const
{
    return (*this + s.m_str);
}
TString TString::operator + (const char *s) const
{
    TString ret;
    int len = m_length + strlen(s ? s : "");
    char *str = reinterpret_cast<char *>(malloc(len + 1));
    if (str) {
        strcpy(str, m_str);
        strcat(str, s ? s : "");
        free(ret.m_str);
        ret.m_str = str;
        ret.m_length = len;
    } else {
        THROW_EXCEPTION(NoEnoughMemoryException, "No memory too add TString values ...");
    }
    return ret;
}
TString &TString::operator += (const TString &s)
{
    return (*this = *this + s);
}
TString &TString::operator += (const char *s)
{
    return (*this = *this + s);
}

/* 赋值操作符重载函数 */
TString &TString::operator = (const TString &s)
{
    return (*this = s.m_str);
}
TString &TString::operator = (const char *s)
{
    if (m_str != s) {
        char *str = strdup(s ? s : "");
        if (str) {
            free(m_str);
            m_str = str;
            m_length = strlen(m_str);

        } else {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory too assign new TString values ...");
        }
    }

    return *this;
}
TString &TString::operator = (const char c)
{
    char s[] = {c, '\0'};
    return (*this = s);
}

TString::~TString()
{
    free(m_str);
}

}