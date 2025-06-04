#include<iostream> 
#include<thread> 
#include<vector>
#include<list>
#include<mutex>
using namespace std;

class text_class
{
public:

	void WriteAval()
	{
		timed_mutex a;
		chrono::microseconds timeout(100);
		if (a.try_lock_for(timeout))//如果在规定时间内拿到了锁
		{
			/*  一波操作 */
			a.unlock();//解锁
		}
		else
		{
			//没拿到锁
		}
		//等到指定时间点
		timed_mutex b;
		chrono::microseconds timeout(100);
		if (b.try_lock_until(chrono::steady_clock::now()+timeout))//如果在规定时间内拿到了锁
		{
			/*  一波操作 */
			b.unlock();//解锁
		}
		else
		{
			//没拿到锁
		}
	}
};
int main(){
	text_class B;
	thread th1(&text_class::WriteAval, ref(B));
	thread th2(&text_class::WriteAval, ref(B));
	th1.join();
	th2.join();
	cout << "主线程结束..." << endl;
}
