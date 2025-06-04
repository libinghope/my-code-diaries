#include<iostream>
using namespace std;

class Person{
    ~Person(){cout<<"调用析构函数"<<endl;}
};
int main(){
    
    void * p = new Person;

    delete p;//这里并不会调用析构函数，如果new p的时候申请了堆内存，将导致内存泄漏

    return 0;
}