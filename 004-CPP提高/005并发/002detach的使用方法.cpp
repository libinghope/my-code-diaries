#include<iostream> 
#include<thread> 
using namespace std;

void myPrint() {
    cout<< "myPrint running ......"<<endl;
    //--------
    for(auto i=0;i<100;i++) {
        cout<<"--------"<<i<<"--------"<<endl;
    }

    cout<< "myPrint 执行结束"<<endl;
}

int main() {
    //使用标准库中的类 thread
    thread myThread(myPrint); //用函数名构造thread对象

    //myThread.join(); //意思是 主线程和子线程汇合，主线程阻塞等待子线程执行完毕,然后主线程继续执行
    //myThread.detach();//detach:直接翻译是分离的意思  主线程不等待子线程,一旦调用过detach就不能再调用join
    if(myThread.joinable()){//joinable 用来判断一个线程是否还可以join或detach
        cout<<"joinable == true"<<endl;
        myThread.join();
    }else{
        cout<<"joinable == false"<<endl;
    }

    cout<< "这里是主线程，执行结束了"<<endl;

    return 0;
}