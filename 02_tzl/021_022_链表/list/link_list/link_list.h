#ifndef LINK_LIST_H
#define LINK_LIST_H

#include "list.h"

namespace DTLib {


template <typename T>
class LinkList : public List<T> {

protected:
    struct Node : public Object {
        T value;
        Node *next;
    };

    Node m_header;
    int m_length;

public:
    LinkList();



};



}


#endif
