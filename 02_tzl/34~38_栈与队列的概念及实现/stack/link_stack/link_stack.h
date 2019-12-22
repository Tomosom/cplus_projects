#ifndef LINK_STACK_H
#define LINK_STACK_H

#include "stack.h"
#include "link_list.h"
#include "exception.h"

namespace DTLib {

template <typename T>
class LinkStack : public Stack<T> {
protected:
    LinkList <T> m_list;

public:
    void push(const T &e)
    {
        m_list.insert(0, e);
    }

    void pop()
    {
        if (m_list.length() > 0) {
            m_list.remove(0);
        } else {
            THROW_EXCEPTION(InvalidOperationException, "No element in current stack...");
        }
    }

    T top() const
    {
        if(m_list.length() > 0) {
            return m_list.get(0);
        } else {
            THROW_EXCEPTION(InvalidOperationException, "No element in current stack...");
        }
    }

    void clear()
    {
        m_list.clear();
    }

    int size() const
    {
        return m_list.length();
    }
    
};




}

#endif