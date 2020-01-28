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
#include "dynamic_array.h"
#include "link_queue.h"
#include "link_stack.h"

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
protected:
    template <typename T>
    DynamicArray<T> *toArray(LinkQueue<T> &queue)
    {
        DynamicArray<T> *ret = new DynamicArray<T>(queue.length());
        if (ret != NULL) {
            for (int i = 0; i < ret->length(); i++, queue.remove()) {
                ret->set(i, queue.front());
            }
        } else {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create ret object ...");
        }

        return ret;
    }

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

    /*
     * BFS : Breadth First Search 广度优先遍历
     *  以二叉树层次遍历的思想对图进行遍历
     * 
     * 广度优先算法
     *  - 原料 : class LinkQueue<T>;
     *  - 步骤 :
     *      1. 将其实定点压入队列中
     *      2. 队头顶点 v 弹出, 判断是否已经标记 (标记 : 转2, 未标记 : 转3)
     *      3. 标记顶点 v, 并将顶点v的邻接顶点压入队列中
     *      4. 判断队列是否为空 (非空 : 转2, 空 : 结束)
     */
    SharedPointer< Array<int> > BFS(int i)
    {
        DynamicArray<int> *ret = NULL;

        if ( (0 <= i) && (i <= vCount()) ) {
            LinkQueue<int> q;
            LinkQueue<int> r;   //  return 队列
            DynamicArray<bool> visited(vCount());

            for(int i = 0; i < visited.length(); i++) {
                visited[i] = false;
            }

            q.add(i);

            while(q.length() > 0) {
                int v = q.front();
                q.remove();

                if (!visited[v]) {
                    SharedPointer< Array<int> > aj = getAdjacent(v);

                    for(int j = 0; j < aj->length(); j++) {
                        q.add((*aj)[j]);
                    }

                    r.add(v);
                    visited[v] = true;
                }
            }

            ret = toArray(r);
        } else {
            THROW_EXCEPTION(InvalidParameterException, "Index i is invalid ...");
        }

        return ret;
    }

    /*
     * DFS : Depth First Search 深度优先遍历
     * 
     * 深度优先算法
     *  - 原料 : class LinkStack<T>;
     *  - 步骤 : 
     *      1. 将起始顶点压入栈中
     *      2. 弹出栈顶顶点v, 判断是否已经标记( 标记 : 转2, 未标记 : 转3 )
     *      3. 标记顶点v, 并将顶点v的邻接顶点压入栈中
     *      4. 判断栈是否为空 ( 非空 : 转2, 空 : 结束 )
     */
    SharedPointer< Array<int> > DFS(int i)
    {
        DynamicArray<int> *ret = NULL;

        if ( (0 <= i) && (i <= vCount()) ) {
            LinkStack<int> s;
            LinkQueue<int> r; // return 队列
            DynamicArray<bool> visited(vCount());

            for (int j = 0; j < visited.length(); j++) {
                visited[j] = false;
            }

            s.push(i);

            while(s.size() > 0) {
                int v = s.top();
                s.pop();
                if (!visited[v]) {
                    SharedPointer< Array<int> > aj = getAdjacent(v);
                    for(int j = aj->length() - 1; j >= 0; j--) {
                        s.push((*aj)[j]);
                    }

                    r.add(v);
                    visited[v] = true;
                }
            }

            ret = toArray(r);

        } else {
            THROW_EXCEPTION(InvalidParameterException, "index i is invalid ...");
        }

        return ret;
    }

};




}


#endif
