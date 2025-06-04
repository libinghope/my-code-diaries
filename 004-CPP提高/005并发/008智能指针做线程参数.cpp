#include<iostream> 
#include<thread> 
#include<string>
using namespace std;

void myPrint(unique_ptr<int> ptr){
    cout<<"智能指针传递过来的值是:"<<*ptr<<endl;
}
int main() {
    cout<<"主线程的this_thread::get_id() = "<<this_thread::get_id()<<endl;

    unique_ptr<int> myptr(new int(110));

    //无法直接这样传递智能指针
    //thread myThread(myPrint,myptr);

    //可以使用move方法来解决
    thread myThread(myPrint,move(myptr));

    myThread.join();
    cout<<"主线程执行完毕，退出..."<<endl;
    return 0;
}