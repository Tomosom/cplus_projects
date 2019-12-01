#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include "array.h"
#include "exception.h"

namespace DTLib {

template <typename T>
class DynamicArray : public Array<T> {
protected:
    int m_length;

public:
    DynamicArray(int length)
    {
        this->m_array = new T[length];
        if (this->m_array != NULL) {
            this->m_length = length;
        } else {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create DynamicArray object ...");
        }
    }

    DynamicArray(const DynamicArray<T> &obj)
    {
        this->m_array = new T[obj.m_length];
        if (this->m_array != NULL) {
            this->m_length = obj.m_length;
            for (int i = 0; i < obj.m_length; i++) {
                this->m_array[i] = obj.m_array[i];
            }
        } else {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create DynamicArray object ...");
        }
    }

    DynamicArray<T> &operator=(const DynamicArray<T> &obj)
    {
        if (this != &obj) { // 避免自赋值
            T *array = new T[obj.m_length];
            if (array != NULL) {
                for (int i = 0; i < obj.m_length; i++) {
                    array[i] = obj.m_array[i];
                }

                T *temp = this->m_array;
                this->m_array = array;
                this->m_length = obj.m_length;
                delete[] temp;
            } else {
                THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create copy object ...");
            }
        }
    }

    int length() const
    {
        return m_length;
    }
    void resize(int length) // 动态重置数组的长度
    {
        if (length != m_length) {
            T *array = new T[length];
            if (array != NULL) {
                int size = (length < m_length) ? length : m_length;
                for (int i = 0; i < size; i++) {
                    array[i] = this->m_array[i];
                }
                T *temp = this->m_array;
                this->m_array = array;
                this->m_length = length;
                delete[] temp;
            } else {
                THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create resize object ...");
            }
        }

    }

    ~DynamicArray()
    {
        delete[] this->m_array;
    }

};

}









#endif


