#include<iostream> 
#include<thread> 
#include<vector>
#include<list>
#include<mutex>
#include<queue>
using namespace std;
class Data_
{
private:
	queue<int> MsgQueue;
	mutex mute;
	condition_variable my_con;
public:
	void GetMsg()
	{
		for (int i = 0; i < 10000; ++i)
		{
			unique_lock<mutex> obj(mute);
			//wait的第二个参数决定是等待还是继续执行
			my_con.wait(obj, [this]
			{
				if (MsgQueue.empty())
					return false;//如果空了的话就直接等待，并且解锁，这
                            //个线程就不要再跑了，等到被唤醒时，再重新加锁，往下执行
				return true;//如果没空，那就读出，继续该进程
			});
			cout << "读出" << MsgQueue.front() << endl;//到了这里就证明，队列没空，可读消息
			MsgQueue.pop();
		}
	}
	void SaveMsh()
	{
		for (int i = 0; i < 10000; ++i)
		{
			unique_lock<mutex> obj(mute);
			MsgQueue.push(i);
			cout << "装入" << i << endl;
			//这时候就可以唤醒读取功能的线程了
			my_con.notify_one();//我已经加入元素，可以开始公平竞争（唤醒）
		}//不一定每次notify_one()时，另一个线程都在等待，也可能人家在干别的事
	}
};

int main(){
	Data_ var;
	thread obj1(&Data_::GetMsg, &var);
	thread obj2(&Data_::SaveMsh, &var);
	obj1.join();
	obj2.join();
}
