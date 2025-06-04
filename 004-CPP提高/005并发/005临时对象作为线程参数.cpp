#include<iostream> 
#include<thread> 
#include<string>
using namespace std;

void myPrint(const int &i,char* buf){
    cout<<"myPrint函数执行..."<<endl;
    cout<<"当前i的地址:"<<&i<<endl;
    cout<<"当前i的值:"<<i<<endl;
    cout<<"当前的buf内容："<<buf<<endl;
}

void myPrint2(const int &i,const string &buf){
    cout<<"myPrint2函数执行..."<<endl;
    cout<<"当前i的地址:"<<&i<<endl;
    cout<<"当前i的值:"<<i<<endl;
    cout<<"当前的buf内容："<<buf.c_str()<<endl;
}

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

};

//引用传参必须使用const
void myPrint3(const A &a){
    cout<<"myPrint3函数执行..."<<endl;
    cout<<"当前A.ma的地址:"<<a.ma<<endl;
}

int main() {
    int var1 = 1;
    int &var2 = var1;
    cout<<"var2也就是var1的地址:"<<&var2<<endl;
    char b[] = "this is buf ...";

    //var1并不能以引用的方式传递参数,依然会复制传参
    //指针b传参，detach执行线程的情况下，一定会出错,一般不要使用detach，容易坏事
    thread myThread(myPrint,var1,b);
    myThread.detach();
    // myThread.join();

    //这里有隐藏的bug，当调用的是detach方法时候，用b 构造string时候，
    //主线程可能已经退出了，b已经释放，无法再隐式转换成string
    thread myThread2(myPrint2,var1,b);
    //可以用下面的方法修复这个bug
    //thread myThread2(myPrint,var1,string(b));
    myThread2.detach();//守护进程在后台运行，很容易出问题


    //匿名对象传参
    //相当于
    /*
    A a(99);
    thread myThread3(myPrint3,a);==>内部再调用myPrint3(a)//会有两次复制构造
    */
    thread myThread3(myPrint3,A(99));
    myThread3.detach();



    cout<<"主线程执行完毕，退出..."<<endl;
    return 0;
}