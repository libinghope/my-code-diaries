#include<iostream> 
#include<thread> 
#include<vector>
#include<list>
#include<mutex>
using namespace std;

/*
实现功能: 有一个网络游戏服务器，有两个线程，一个线程搜集玩家命令(用数字表示)，并把命令数据写到一个队列中

另外一个线程从队列中取出用户命令，解析，并执行用户命令所指示的动作
*/

class GameServer{
public:
    //把命令写入到队列中
    void inCmd(){
        
        for (int i=0;i<10000;++i){
            cout<<"收到命令："<<i<<endl;
            /*lock_guard 是一个类模板，会在构造函数中上锁，在析构函数中解锁，和智能指针类似
            第二个参数有三种情况 
            adopt_lock：如果已经加锁，则不用再次加锁

            try_to_lock:尝试去锁，如果没锁成功也会返回，不会卡死在那，然后可用owns_lock()得到是否上锁的信息
            unique_lock<mutex> obj(mute,try_to_lock);
            if (obj.owns_lock()) 
                {//如果锁上了要怎么做…}
            else 
                {//没锁上也可以干别的事}

            defer_lock:用一个还没上锁的mutex变量初始化一个对象，自己可以在后续代码段中的某个位置加锁，
            而离开作用域时，也能帮助我们解锁，当然我们也能提前手动a.unlock()解锁
            mutex a;
	        unique_lock<mutex> obj(a,defer_lock);
	        // 做一些操作
	        a.lock();//也可结合条件判断语句使用a.try_lock() ，若成功锁上能返回true，否则返回false 
            */
           
            lock_guard<std::mutex> lock(mtx);
            cmd_list.push_back(i);//假设这就是收到了用户的命令
        }
    }

    void outCmd(){

        for(int i=0;i<10000;++i){
            if(cmd_list.empty()){
                cout<<"cmd_list 为空"<<endl;
            }else{
                //从头开始去数据
                mtx.lock();
                int cmd = cmd_list.front();
                cmd_list.pop_front();
                cout<<"处理了命令"<<i<<endl;
                mtx.unlock();
                //处理命令，把命令从容器中移除
            }
        }
        cout<<"outCmd end..."<<endl;
    }

private:
    list<int> cmd_list;
    mutex mtx;
};

int main() {
    GameServer gameServer;
    thread inThread(&GameServer::inCmd,&gameServer);//第二个参数要使用指针，避免被复制
    thread outThread(&GameServer::outCmd,&gameServer);

    inThread.join();
    outThread.join();

    cout<< "这里是主线程，执行结束了"<<endl;
    return 0;
}