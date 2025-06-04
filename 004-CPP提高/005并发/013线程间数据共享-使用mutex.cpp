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
            mtx.lock();
            cmd_list.push_back(i);//假设这就是收到了用户的命令
            mtx.unlock();
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