#pragma once
#include <iostream>
using namespace std;
class MyString
{
public:
    MyString(char *);
    MyString(const MyString &);
    ~MyString();

    char &operator[](int index); //[]重载

    //=号重载
    MyString &operator=(const char *str);
    MyString &operator=(const MyString &str);

    MyString &operator+(const char*);
    MyString &operator+(const MyString &);

    void println();

    inline int getSize(){return m_Size;}
    inline char* getCharArr(){return pString;}

private:
    char *pString; //指向堆区空间
    int m_Size;    //字符串长度 不算'\0'
};