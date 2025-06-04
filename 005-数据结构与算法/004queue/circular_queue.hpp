#ifndef __CIRCULAR_QUEUE_HPP__
#define __CIRCULAR_QUEUE_HPP__

template <typename T>
class CircularQueue
{
public:
    enum{
        QUEUE_EMPTY = 0,
        QUEUE_FULL  = 1
    };
    CircularQueue(int size)
    {
        this->size = size;
        pData= new T[size + 1]; //多一个判空元素
        front = -1;
        rear = -1;
    }
    ~CircularQueue()
    {
        if (pData)
        {
            delete[] pData;
            pData = nullptr;
        }
    }
    inline bool full()
    {
        return (rear % size + 2) == front;
    }
    inline bool empty()
    {
        return front-1 == rear;
    }

    int enqueue(T t)
    {
        if(full()){/*throw "queue is full !";*/return -1;}
        if(-1 != rear) {rear = rear % size;}
        if(-1 == front) {front = 0;}
        pData[++rear] = t;
        return 0;
    }
    T dequeue()
    {
        if (empty())
        {
            throw "Pop from a empty queue!";
        }
        T t = pData[front];
        if(front == rear){
            front = rear = -1;
        }else{
            front = (front+1)%size;
        }
        return t;
    }

private:
    T *pData;
    int front;
    int rear;
    unsigned int size;
};

#endif