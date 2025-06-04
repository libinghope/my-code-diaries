#include <iostream>

using namespace std;

int a = 10;//定义一个全局变量
int main(){
    int a = 20;//定义一个局部变量和全局变量同名
	//打印局部变量a
	cout << "局部变量a:" << a << endl;
	//打印全局变量a
	cout << "全局变量a:" << ::a << endl;

    
    return 0;
}