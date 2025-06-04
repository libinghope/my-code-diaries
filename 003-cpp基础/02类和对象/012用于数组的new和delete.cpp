#include<iostream>

using namespace std;

class Person{};

int main(){

    //创建字符数组
    char* pStr = new char[100];
    //创建整型数组
    int* pArr1 = new int[100]; 
    //创建整型数组并初始化 下面这条代码在MAC上报错
    // int* pArr2 = new int[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    //创建对象数组
    Person * persons = new Person[100];

    //释放数组内存
    delete[] pStr;
    delete[] pArr1;
    // delete[] pArr2;
    delete[] persons;

    cout<<"game over......";
    return 0;
}