#include<iostream> 
#include<thread> 
using namespace std;

int main() {
    auto myLamThread = []{
        cout<<"lamda表达式线程开始执行..."<<endl;
        //do something

        cout<<"lamda表达式线程执行结束..."<<endl;

    };
    thread myThread(myLamThread);

    // myThread.join();
    myThread.detach();
    cout<< "这里是主线程，执行结束了"<<endl;

    return 0;
}