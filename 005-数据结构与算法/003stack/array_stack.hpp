#ifndef __ARRAY_STACK_H__
#define __ARRAY_STACK_H__

#define MAX_SIZE 100

template<typename T>
class ArrayStack{
    public:
    ArrayStack(){
        top = -1;
        pArr = new T[MAX_SIZE]
    }

    ~ArrayStack(){
        if(pArr){
            delete[] pArr;
            pArr = null;
        }
    }

    T pop(){
        if(-1 != top){
           return pArr[top--];
        }
        return null;
    }
        
    int push(T t){
        if(top != MAX_SIZE-1){
            pArr[top++] = t;
        }
        
        return -1;
    }

    bool isEmpty(){
        return -1 == top;
    }
    inline int size(){return size;}

    private:
    T * pArr;
    int top; 
    int size;
};

#endif