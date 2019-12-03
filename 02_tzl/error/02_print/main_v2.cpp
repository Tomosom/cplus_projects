#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define THROW_EXCEPTION(e, m) (throw e(m, __FILE__, __LINE__))

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
            }
        }
        return ret;
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

int main()
{
    LinkList<int> list;
    for(int i = 0; i < 5; i++) {
        list.insert(i);
    }

    cout << "length " << list.length() << endl;

    for(int i = 0; i < list.length(); i++) {
        int v = 0;
        list.get(i, v);
        cout << v << endl;
    }
    return 0;

}

