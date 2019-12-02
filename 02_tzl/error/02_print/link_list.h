#ifndef LINK_LIST_H
#define LINK_LIST_H

#include "exception.h"

template <typename T>
class LinkList {

protected:
    struct Node {
        T value;
        Node *next;
    };

    mutable Node m_header;
    int m_length;

public:
    LinkList()
    {
        m_header.next = NULL;
        m_length = 0;
    }


	bool insert(const T &e)
    {
        return insert(m_length, e);
    }

	bool insert(int i, const T &e)
    {
        bool ret = ((0 <= i) && (i <= m_length));
        if (ret) {
            Node *node = new Node();
            if(node != NULL) {
                Node *current = &m_header;
                for(int p = 0; p < i; p++) {
                    current = current->next;
                }

                node->value = e;
                node->next = current->next;
                current->next = node;

                m_length++;
            } else {
                THROW_EXCEPTION(NoEnoughMemoryException, "No memory to insert new element");
            }
        }
    }
	bool remove(int i)
    {
        bool ret = ((0 <= i) && (i < m_length));
        if (ret) {
            Node *current = &m_header;
            for(int p; p < i; p++) {
                current = current->next;
            }

            Node *toDel = current->next;
            current->next = toDel->next;
            delete toDel;
            m_length--;
        }

        return ret;
    }


    T get(int i) const
    {
#if 1
        T ret;
        if (get(i, ret)) {
            //std::cout << std::endl;
            //printf("\n");
            get(i, ret);
            return ret;
        } else {
            //std::cout << "else" << std::endl;
            //throw IndexOutOfBoundsException("Invalid parameter i to get element...", __FILE__, __LINE__);
        }
#else
        T ret;
        get(i, ret);
        return ret;
#endif
    }

	bool get(int i, T &e) const
    {
        bool ret = ((0 <= i) && (i < m_length));
        if (ret) {
            Node *current = &m_header;
            for(int p; p < i; p++) {
                current = current->next;
            }

            e = current->next->value ;
        }
        return ret;
    }
	int length() const
    {
        return m_length;
    }

    ~LinkList()
    {
        while(m_header.next) {
            Node *toDel = m_header.next;
            m_header.next = toDel->next;
            delete toDel;
        }
        m_length = 0;
    }

};


#endif
