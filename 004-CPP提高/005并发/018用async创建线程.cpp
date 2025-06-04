#include<iostream> 
#include<thread> 
#include<vector>
#include<list>
#include<mutex>
#include<queue>
#include <future>
using namespace std;

int TextThread(int num)
{
    cout << "我是线程" << this_thread::get_id() << endl;
    /*  …  */
    cout << "线程" << this_thread::get_id() << "执行结束" << endl;
    return num;
}

int main(){
	//这里会异步的创建一个线程,用futuer接收线程函数的返回值
    future result = async(launch::async,TextThread,6);//

	//获取线程返回的结果
    cout << result.get();

	return 0;
}
