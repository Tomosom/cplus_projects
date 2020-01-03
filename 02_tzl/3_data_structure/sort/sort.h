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

    // 冒泡排序，该排序是稳定的
    template <typename T>
    static void Bubble(T array[], int len, bool min2max = true) // O(n2)
    {
        bool exchange = true;

        for (int i = 0; (i < len) && exchange; i++) {
            exchange = false;
            for (int j = len - 1; j > i; j--) {
                if (min2max ? (array[j] < array [j - 1]) : (array[j] > array [j - 1])) {
                    Swap(array[j], array[j - 1]);
                    exchange = true;
                }
            }
        }
    }

    /* 希尔排序 - 插入排序
     * 基本思想：将待排序列划分为若干组，在每一组内进行插入排序，以使整个序列基本有序，然后再对整个序列进行插入排序
     */
    template <typename T>
    static void Shell_from_insert(T array[], int len, bool min2max = true) // O(n3/2)
    {
        int d = len;
        do {
            d = d / 3 + 1; // 实践证明这样减小d比较好，也可以d--, 但效率不会好
            for (int i = d; i < len; i += d) {
                int k = i;
                T e = array[i];

                for (int j = i - d; (j >= 0) && (min2max ? (array[j] > e) : (array[j] < e)); j -= d) {
                    array[j + d] = array[j];
                    k = j;
                }

                if (k != i) {
                    array[k] = e;
                }
            }
        } while(d > 1);
    }
#if 1
    /* 希尔排序 - 冒泡排序
     * 基本思想：将待排序列划分为若干组，在每一组内进行冒泡排序，以使整个序列基本有序，然后再对整个序列进行冒泡排序
     */
    template <typename T>
    static void Shell_from_bubble(T array[], int len, bool min2max = true) // test
    {
        int d = len;
        do {
            d = d / 3 + 1; // 实践证明这样减小d比较好，也可以d--, 但效率不会好
            bool exchange = true;
            for (int i = d - 1; (i < len - 1) && exchange; i += d) {
                exchange = false;
                // 定位到分组的最后一个
                int j = i;
                while (j < len - d) {
                    j += d;
                }
                for (; j > i; j -= d) {
                    if (min2max ? (array[j] < array [j - d]) : (array[j] > array [j - d])) {
                        Swap(array[j], array[j - d]);
                        exchange = true;
                    }
                }
            }
        } while(d > 1);
    }
#endif


};



}


#endif