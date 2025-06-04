#ifndef __LINKED_LIST_HPP__
#define __LINKED_LIST_HPP__

template <typename T>
class LinkedListNode
{
public:
    LinkedListNode() {}
    LinkedListNode(T t) { this->t = t; }
    T t;
    LinkedListNode *next;
};

template <typename T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void add(T t);
    T get(int index);
    int insert(T t, int index);
    inline unsigned getLength() { return this->length; }

private:
    unsigned int length;
    LinkListNode *head; //链表头 空节点
    LinkListNode *tag;
};

template <typename T>
LinkedList<T>::LinkedList()
{
    head = new LinkedListNode<T>;
    tag = head;
    length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    while (head->next)
    {
        LinkedListNode * p = head->next->next;
        delete head->next;
        head->next = p;
    }
    delete head;
}

template <typename T>
void LinkedList<T>::add(T t)
{
    tag->next = new LinkedListNode<T>(t);
    tag = tag->next;
}

template <typename T>
T LinkedList<T>::get(int index)
{
    int i = 0;
    LinkedListNode<T> *p = head;
    while (i < index)
    {
        i++;
        p = p->next;
    }
    return p->t;
}

template <typename T>
int LinkedList<T>::insert(T t, int index)
{
    if (index > -1 && index < length)
    {
        LinkedListNode<T> *new_node = new LinkedListNode<T>(t);
        LinkedListNode<T> *p = head;
        int i = 0;
        while (i < index)
        {
            p = p->next;
            i++;
        }
    }
    return -1;
}

#endif