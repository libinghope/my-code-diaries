#ifndef __LINKED_QUEUE_HPP__
#define __LINKED_QUEUE_HPP__

template <typename T>
class LinkedQueue
{
public:
    struct _node
    {
        _node(){}
        _node(T t){this->t=t;}
        T t;
        _node *next;
    };
    
    LinkedQueue()
    {
        head = new _node;
        head->next = nullptr;
        tail = head;
    }
    ~LinkedQueue()
    {
        while (head->next)
        {
            _node *p = head->next->next;
            delete head->next;
            head->next = p;
        }
        delete head;
    }

    int enqueue(T t)
    {
        tail->next = new _node(t);
        tail = tail->next;
    }

    T dequeue()
    {
        T _t = head->next->t;
        _node * next2 = head->next->next;
        delete head->next;
        head->next = next2;
        return _t;
    }

    bool empty(){
        return head->next == nullptr;
    }

private:
    int length = 0;
    _node *head = nullptr;
    _node *tail = nullptr;
};
#endif
