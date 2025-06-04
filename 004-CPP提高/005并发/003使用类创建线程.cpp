#include<iostream> 
#include<thread> 
using namespace std;

class ThreadA{
public:
    int ma;
    ThreadA(int m): ma(m){
        this->ma = m;
        cout<<"调用构造函数"<<endl;
    }
    ThreadA(const ThreadA &t): ma(t.ma){
        this->ma = t.ma;
        cout<<"调用复制构造函数,当前ma的值:"<<ma<<endl;
    }
    ~ThreadA(){
        cout<<"调用析构函数"<<endl;
    }
    void operator()(int b)//需要重载()，才能调用
    {
        cout<<"用类生成的线程对象 running......."<<endl;
        cout<<"ma的当前值是:"<<ma<<endl;
        cout<<"传递过来的参数b的值:"<<b<<endl;

        cout<<"子线程结束运行......"<<endl;
    }
};

int main() {
    ThreadA ta(6);//这里调用构造函数
    //使用标准库中的类 thread
    //用类对象构造thread对象,对象做参数时候会调用复制构造函数,
    //在MAC下测试，发现调用了两次复制构造函数,为什么?
    thread myThread(ta,100);

    myThread.join();
    // myThread.detach();
    cout<< "这里是主线程，执行结束了"<<endl;

    return 0;
}