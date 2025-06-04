#include<iostream> 
#include<thread> 
#include<string>
using namespace std;

class A{
public:
    int ma;
    A(int a):ma(a){
        cout<<"构造函数执行..."<<endl;
    }
    A(const A &a):ma(a.ma){
        cout<<"复制构造函数执行..."<<endl;
    }
    ~A(){
        cout<<"析构函数执行..."<<endl;
    }
    void operator()(){
        cout<<"--------子线程开始-----------"<<endl;
        cout<<"子线程的this_thread::get_id() = "<<this_thread::get_id()<<endl;
        ma++;
        cout<<"---------子线程结束----------"<<endl;
    }
};

int main() {
    cout<<"主线程的this_thread::get_id() = "<<this_thread::get_id()<<endl;
    A a(110);
    thread myThread(std::ref(a));
    myThread.join();
    cout<<"当前A.ma的值:"<<a.ma<<endl;
    cout<<"主线程执行完毕，退出..."<<endl;
    return 0;
}