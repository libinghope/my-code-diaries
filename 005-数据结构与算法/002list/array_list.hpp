#ifndef __ARRAY_LIST_HPP__
#define __ARRAY_LIST_HPP__

// C++实现类似java中的ArrayList
#include <string.h>

template<typename T>
class ArrayList{
    public:
        ArrayList();
        ~ArrayList();
        int add(T t);
        T get(int index);
        int insert(T t, int index);
        inline unsigned getLength(){return this->length;}
        int reSize(int reSize = 10);
    private:
        T *tPtr;
        unsigned int length;//对外显示的长度
        unsigned int size;//实际开辟的空间长度
        static unsigned int default_capacity = 10;//第一次默认开辟的空间长度
};

template<typename T>
ArrayList<T>::ArrayList(){
    this->tPtr = new T[default_capacity];
    size = default_capacity;
    length = 0;
}

template<typename T>
ArrayList<T>::~ArrayList(){
    if(this->tPtr){
        delete[] tPtr;
        tPtr = NULL;
    }
}

template<typename T>
int ArrayList<T>::reSize(int resize){
    T* new_tPtr = new T[this->size + resize];
    memcpy(new_tPtr, tPtr, sizeof(T) * size);
    size += resize;
    T* old_tPtr = this->tPtr;
    this->tPtr = new_tPtr;
    delete[] old_tPtr;
    old_tPtr = NULL;
    return 0;
}

template<typename T>
int ArrayList<T>::add(T t){
    if(used_size >= size){
        this->reSize(default_capacity);
    }else{
        tPtr[used_size] = t;
    }

    return ++used_size;
}

template<typename T>
T ArrayList<T>::get(int index){
    return tPtr[index];
}

template<typename T>
int ArrayList<T>::insert(T t, int index){
    T* new_tPtr = new T[this->size + default_capacity];
    memcpy(new_tPtr, tPtr, sizeof(T) * index);
    memcpy(&new_tPtr[index+1], &tPtr[index], sizeof(T) * (size-index));
    new_tPtr[index] = t;
    T* old_tPtr = this->tPtr;
    this->tPtr = new_tPtr;
    delete[] old_tPtr;
    old_tPtr = NULL;
    this->size += default_capacity;
    ++this->used_size;
    return 0;
}
#endif
