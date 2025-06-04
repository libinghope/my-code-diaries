#include<stdio.h>
#include<stdlib.h>

/*linux系统中system函数位于 <stdlib.h>中(windows不需要头文件),mac没有pause指令
原型: int system(const char *command);
功能：在已经运行的程序中执行另外一个外部程序
参数：外部可执行程序名字
返回值：
    成功：不同系统返回值不一样
    失败：通常是 - 1

C语言所有的库函数调用，只能保证语法是一致的，
但不能保证执行结果是一致的，同样的库函数在不同的操作系统下执行结果可能是一样的，
也可能是不一样的。
*/
int main(){
    //启动系统记事本
    // system("notepad");

    //windows下启动画图工具
    system("mspaint");

    //启动系统计算器
    // system("calc");
    system("pause");//暂停终端，否则会一闪而过
    return 0;
}