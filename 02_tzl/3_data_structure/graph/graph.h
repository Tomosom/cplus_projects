/*
 * 基本思想：
 *  - 用一维数组存储顶点：描述顶点相关的数据
 *  - 用二维数组存储边：描述顶点间的关系和权
 */

#ifndef GRAPH_H
#define GRAPH_H

#include "object.h"
#include "shared_pointer.h"
#include "array.h"

namespace DTLib {

// 边相关的数据类型
template <typename E>
struct Edge : public Object {
    int b;
    int e;
    E data;

    Edge(int i = -1, int j = -1)
    {
        b = i;
        e = j;
    }

    Edge(int i, int j, const E &value)
    {
        b = i;
        e = j;
        data = value;
    }

    bool operator == (const Edge<E> &obj)
    {
        return (b == obj.b) && (e == obj.e);
    }

    bool operator != (const Edge<E> &obj)
    {
        return !(*this == obj);
    }
};

template <typename V, typename E>
class Graph : public Object {
public:
    /* 获取顶点相关的数据元素值 */
    virtual V getVertex(int i) = 0;
    virtual bool getVertex(int i, V &value) = 0;
    /* 设置顶点相关的数据元素值 */
    virtual bool setVertex(int i, const V &value) = 0;
    /* 获取邻接顶点 */
    virtual SharedPointer< Array<int> > getAdjacent(int i) = 0;
    /* 获取边相关的数据元素值 */
    virtual E getEdge(int i, int j) = 0;
    virtual bool getEdge(int i, int j, E &value) = 0;
    /* 设置边相关的数据元素值 */
    virtual bool setEdge(int i, int j, const E &value) = 0;
    /* 删除边 */
    virtual bool removeEdge(int i, int j) = 0;
    /* 获取定点数 */
    virtual int vCount() = 0;
    /* 获取边数 */
    virtual int eCount() = 0;
    /* 获取出度 */
    virtual int OD(int i) = 0;
    /* 获取入度 */
    virtual int ID(int i) = 0;
    /* 获取总的度 */
    virtual int TD(int i)
    {
        return OD(i) + ID(i);
    }
};

}


#endif
