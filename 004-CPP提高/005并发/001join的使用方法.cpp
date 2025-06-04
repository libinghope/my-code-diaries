#include<iostream> 
#include<thread> 
using namespace std;

void myPrint() {
    cout<< "myPrint running ......"<<endl;
    //--------
    //do something

    cout<< "myPrint 执行结束"<<endl;
}

int main() {
    //使用标准库中的类 thread
    thread myThread(myPrint); //用函数名构造thread对象
    //thread myThread1(myPrint); //用函数名构造thread对象

    myThread.join(); //意思是 主线程和子线程汇合，主线程阻塞等待子线程执行完毕,然后主线程继续执行
    //myThread1.join();

    cout<< "这里是主线程，执行结束了"<<endl;

    return 0;
}