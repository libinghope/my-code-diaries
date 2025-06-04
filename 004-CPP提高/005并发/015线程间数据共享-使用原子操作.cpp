#include<iostream> 
#include<thread> 
#include<vector>
#include<list>
#include<mutex>
using namespace std;

class text_class
{
public:
    /*
    保证对某个变量进行一元操作符运算的时候，能够不被打断，
    只需将该变量通过atomic这个类模板声明即可，效率比互斥锁高
    */
	atomic<int> count;
	text_class():count(0){}
	void WriteAval()
	{
		for (int i = 0; i < 100000; ++i)
		{
			++(count);//这动作会变成原子操作
		}
	}
};
int main(){
	text_class B;
	thread th1(&text_class::WriteAval, ref(B));
	thread th2(&text_class::WriteAval, ref(B));
	th1.join();
	th2.join();
	cout << B.count << endl;
}
