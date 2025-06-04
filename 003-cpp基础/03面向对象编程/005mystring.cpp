#include "005mystring.h"

MyString::MyString(char *pstr)
{
    this->pString = new char[(strlen(pstr) + 1)];
    strcpy(pString, pstr);
    m_Size = strlen(pstr);
}

MyString::MyString(const MyString &str)
{
    this->pString = new char[(str.m_Size + 1)];
    strcpy(pString, str.pString);
    m_Size = str.m_Size;
}

MyString::~MyString()
{
    if (pString)
    {
        delete[] pString;
        pString = NULL;
    }
}

char &MyString::operator[](int index)
{
    return pString[index];
}

MyString &MyString::operator=(const char *pstr)
{
    if (pString)
    {
        delete[] pString;
    }
    pString = new char[strlen(pstr)+1];
    strcpy(pString, pstr);
    m_Size = strlen(pstr);
    return *this;
}

MyString &MyString::operator=(const MyString &str){
    if(this == &str){
        return *this;
    }
    if (pString)
    {
        delete[] pString;
    }
    pString = new char[str.m_Size+1];
    strcpy(pString, str.pString);
    m_Size = str.m_Size;
    return *this;
}

MyString &MyString::operator+(const char* pstr){
    int new_size = m_Size+strlen(pstr);
    char * newPtr = new char[new_size+1];
    memset(newPtr, 0, new_size);
    strcpy(newPtr, pString);
    strcat(newPtr, pstr);
    if (pString)
    {
        delete[] pString;
    }
    strcpy(pString, newPtr);
    delete[] newPtr;
    m_Size = new_size;
    return *this;
}
MyString &MyString::operator+(const MyString &str){
    int new_size = m_Size + str.m_Size;
    char * newPtr = new char[new_size+1];
    strcpy(newPtr, pString);
    strcat(newPtr, str.pString);
    if (pString)
    {
        delete[] pString;
    }
    pString = newPtr;
    m_Size = new_size;
    return *this;
}

void MyString::println(){
    cout<<pString<<endl;
}