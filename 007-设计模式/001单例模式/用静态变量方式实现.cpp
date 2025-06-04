#include<iostream>
using namespace std;

/*假设一个公司只有一台打印机，给所有的员工使用，每次使用都有使用记录(简单的累计使用次数)*/
class Printer{
public:
    //构造函数私有，只能通过下面这个方法获得实例对象了
	static Printer* getInstance(){ return pPrinter;}
	void PrintText(string text){
		cout << "打印内容:" << text << endl;
		cout << "已打印次数:" << mTimes << endl;
		cout << "--------------" << endl;
		mTimes++;
	}
private:
	Printer(){ mTimes = 0; }//构造函数私有化
	Printer(const Printer&){}//拷贝构造也要私有化，确保外部无法生成对象实例
private:
	static Printer* pPrinter;//在编译时候就已经有了(也可以定义成全局静态变量),所以是线程安全的
	int mTimes;//pPrinter只有一个，所以mTimes也只能有一个了
};

//
Printer* Printer::pPrinter = new Printer;

int main(){
	Printer* printer = Printer::getInstance();
	printer->PrintText("离职报告!");
	printer->PrintText("入职合同!");
	printer->PrintText("提交代码!");

    return 0;
}
