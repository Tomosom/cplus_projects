#ifndef SORT_H
#define SORT_H

#include <iostream>
#include "object.h"

using namespace std;
using namespace DTLib;

namespace DTLib {

class Sort : public Object {
private: // 构造函数被定义为私有的，表明Sort这个类不可能有对象的
    Sort();
    Sort(const Sort&);
    Sort &operator = (const Sort &);

    template <typename T>
    static void Swap(T &a, T &b)
    {
        T c(a);
        a = b;
        b = c;
    }

public:
    // 选择排序, 该排序是不稳定的，会打破原先相同数据元素的先后关系
    template <typename T>
    static void Select(T array[], int len, bool min2max = true) // O(n2)
    {
        for(int i = 0; i < len; i++) {
            int min = i;
            for (int j = i + 1; j < len; j++) {
                if (min2max ? (array[min] > array[j]) : (array[min] < array[j])) {
                    min = j;
                }
            }
            if (min != i) {
                Swap(array[i], array[min]);
            }
        }
    }

    // 插入排序，该排序是稳定的
    template <typename T>
    static void Insert(T array[], int len, bool min2max = true) // O(n2)
    {
        for (int i = 1; i < len; i++) {
            int k = i;
            T e = array[i];

            for (int j = i - 1; (j >= 0) && (min2max ? (array[j] > e) : (array[j] < e)); j--) {
                array[j + 1] = array[j];
                k = j;
            }

            if (k != i) {
                array[k] = e;
            }
        }
    }

};



}


#endif