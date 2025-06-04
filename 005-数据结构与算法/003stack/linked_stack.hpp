#ifndef __LINK_STACK_H__
#define __LINK_STACK_H__
#include<iostream>

template<typename T>
class LinkedStackNode
{
    public:
    LinkedStackNode<T>(){}
    LinkedStackNode<T>(T _t){ t = _t; }
    T t;
    LinkedStackNode* next;
};
template<typename T>
class LinkedStack{
    public:
    LinkedStack<T>(){
        top = new LinkedStackNode<T>();
        top->next = NULL;
    }

    ~LinkedStack(){
        LinkedStackNode<T>* p = NULL;
        while (top->next){
            p = top->next;
            top->next = top->next->next;
            delete p;
        }
        delete top;
        top = NULL;
    }

    T pop(){
        LinkedStackNode<T>* p = top->next;
        if(p){
            top->next = top->next->next;
            return p->t;
        }
        return NULL;
    } 
        
    void push(T t){
        if(!top->next){
            top->next = new LinkedStackNode<T>(t);
            return;
        }
        LinkedStackNode<T> * p = top->next;
        top->next = new LinkedStackNode<T>(t);
        top->next->next = p;
    }

    bool isEmpty(){
        return NULL == this->top->next;
    }

    private:
    LinkedStackNode<T>* top;
};

#endif