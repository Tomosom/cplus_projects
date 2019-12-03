#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define THROW_EXCEPTION(e, m) (throw e(m, __FILE__, __LINE__))

class Exception {
protected:
    char *m_message;
    char *m_location;

    void init(const char *message, const char *file, int line)
    {
        m_message = message ? strdup(message) : NULL; /* patch lesson 26 */
        if (file != NULL) {
            char sl[16] = {0};

            sprintf(sl, "%d", line);

            m_location = static_cast<char *>(malloc(strlen(file) + strlen(sl) + 2));
            if(m_location != NULL) {
                m_location = strcpy(m_location, file);
                m_location = strcat(m_location, ":");
                m_location = strcat(m_location, sl);
            }
        } else {
            m_location = NULL;
        }
    }

public:
    Exception(const char *message)
    {
        init(message, NULL, 0);
    }
    Exception(const char *file, int line)
    {
        init(NULL, file, line);
    }
    Exception(const char *message, const char *file, int line)
    {
        init(message, file, line);
    }

    Exception(const Exception &e)
    {
        m_message = strdup(e.m_message);
        m_location = strdup(e.m_location);
    }

    Exception &operator=(const Exception &e)
    {
        if(this != &e) {
            free(m_message);
            free(m_location);
            m_message = strdup(e.m_message);
            m_location = strdup(e.m_location);
        }

        return *this;
    }

    virtual const char *message() const
    {
        return m_message;
    }
    virtual const char *location() const
    {
        return m_location;
    }

    virtual ~Exception()
    {
        free(m_message);
        free(m_location);
    }
};
class IndexOutOfBoundsException : public Exception
{
public:
    IndexOutOfBoundsException() : Exception(0) { }
    IndexOutOfBoundsException(const char *message) : Exception(message) { }
    IndexOutOfBoundsException(const char *file, int line) : Exception(file, line) { }
    IndexOutOfBoundsException(const char *message, const char *file, int line) : Exception(message, file, line) { }

    IndexOutOfBoundsException(const IndexOutOfBoundsException &e) : Exception(e) { }

    IndexOutOfBoundsException& operator=(const IndexOutOfBoundsException &e)
    {
        Exception::operator=(e);
        return *this;
    }

};
class NoEnoughMemoryException : public Exception
{
public:
    NoEnoughMemoryException() : Exception(0) { }
    NoEnoughMemoryException(const char *message) : Exception(message) { }
    NoEnoughMemoryException(const char *file, int line) : Exception(file, line) { }
    NoEnoughMemoryException(const char *message, const char *file, int line) : Exception(message, file, line) { }

    NoEnoughMemoryException(const NoEnoughMemoryException &e) : Exception(e) { }

    NoEnoughMemoryException& operator=(const NoEnoughMemoryException &e)
    {
        Exception::operator=(e);
        return *this;
    }

};


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


    T get(int i) const
    {
#if 1
        T ret;
        if (get(i, ret)) {
            //std::cout << std::endl;
            //printf("\n");
            //get(i, ret);
            return ret;
        } else {
            //throw "hello girl";
            //std::cout << "else" << std::endl;
            throw IndexOutOfBoundsException("Invalid parameter i to get element...", __FILE__, __LINE__);
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

int main()
{
    LinkList<int> list;
    for(int i = 0; i < 5; i++) {
        list.insert(i);
    }

    cout << "length " << list.length() << endl;

    for(int i = 0; i < list.length(); i++) {
        /*
        int v = 0;
        list.get(i, v);
        cout << v << endl;
        */
        //cout << " : " << i << endl;
        cout << "main : " << list.get(i) << endl;
        //list.get(i);
    }
    return 0;

}
