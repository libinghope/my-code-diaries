#include<iostream> 
#include<thread> 
#include<vector>
using namespace std;

int a[3]{1,2,3};
//线程入口函数
void myPrint(int num) {
    cout<< "thread编号: "<<num<<" 开始执行"<<endl;
    //--------
    //do something
    //--------
    //只对数据进行读操作
    cout<<"|||||------------thread编号:"<<num<<a[0]<<a[1]<<a[2]<<endl;

    cout<< "thread编号: "<<num<<" 执行结束"<<endl;
}

int main() {
    vector<thread> ths;

    for(int i=0;i<10;i++){
        //thread t(myPrint,i);
        //把线程放入容器中，当线程数量比较多的时候使用非常方便
        ths.push_back(thread(myPrint,i));
    }
    for(auto iter=ths.begin();iter!=ths.end();iter++){
        iter->join();//等待所有子线程结束
    }

    cout<< "这里是主线程，执行结束了"<<endl;

    return 0;
}