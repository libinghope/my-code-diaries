#ifndef __ARRAY_QUEUE_HPP__
#define __ARRAY_QUEUE_HPP__
#include <string.h>

/*
队列: 数据从尾部进入，头部取出
这里使用的是动态数组实现方法,出队一个元素，后面的全部向前移动一下
*/
template <typename T>
class ArrayQueue
{
public:
    ArrayQueue(int size)
    {
        this->pt = new T[size];
        this->size = size;
        tail = pt;
        length = 0;
    }
    ~ArrayQueue()
    {
        if (pt)
        {
            delete[] pt;
            pt = NULL;
            tail = NULL;
            length = 0;
        }
    }

    int enqueue(T t)
    {
        if (length < size)
        {
            *tail = t;
            ++length;
            ++tail;
            return 0;
        }
        return -1;
    }

    T dequeue()
    {
        if (length <= 0)
        {
            throw "Pop data from a empty queue!";
        }
        T t = pt[0];
        for (int i = 0; i < length; i++)
        {
            pt[i] = pt[i + 1];
        }
        tail--;
        length--;
        return t;
    }
    inline int getLength() { return this->length; }
    inline bool empty() { return 0 == length; }
    inline bool full() { return length == size; };

private:
    int size;   /*队列的大小*/
    int length; /*当前存储数据的大小*/
    T *tail; //尾地址
    T *pt;   //首地址
};

#endif
