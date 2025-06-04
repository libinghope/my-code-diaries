#include <stdio.h>
#include <stdlib.h>

/*
在linux系统下，可以用size指令查看一个可执行程序的信息，
可以看到整个程序分为  代码区(text) 静态数据/全局初始化数据区(data)
和未初始化数据区(bss).
等程序加载到内存，开始运行的时候，又额外增加了堆区和栈区 
*/

/*----------------------------------------------------------------------
类型	        作用域	    生命周期	    存储位置
auto变量	    一对{}内	当前函数	    栈区
static局部变量	一对{}内	整个程序运行期	初始化在data段，未初始化在BSS段
extern变量	    整个程序	整个程序运行期	初始化在data段，未初始化在BSS段
static全局变量	当前文件	整个程序运行期	初始化在data段，未初始化在BSS段
extern函数	    整个程序	整个程序运行期	代码区
static函数	    当前文件	整个程序运行期	代码区
register变量	一对{}内	当前函数	    运行时存储在CPU寄存器
字符串常量	    当前文件	整个程序运行期	 data段
------------------------------------------------------------------------
*/

int e;
static int f;
int g = 10;
static int h = 10;
int main()
{
	int a;
	int b = 10;
	static int c;
	static int d = 10;
	char *i = "test";
	char *k = NULL;

	printf("&a\t %p\t //局部未初始化变量\n", &a);
	printf("&b\t %p\t //局部初始化变量\n", &b);

	printf("&c\t %p\t //静态局部未初始化变量\n", &c);
	printf("&d\t %p\t //静态局部初始化变量\n", &d);

	printf("&e\t %p\t //全局未初始化变量\n", &e);
	printf("&f\t %p\t //全局静态未初始化变量\n", &f);

	printf("&g\t %p\t //全局初始化变量\n", &g);
	printf("&h\t %p\t //全局静态初始化变量\n", &h);

	printf("i\t %p\t //只读数据(文字常量区)\n", i);

	k = (char *)malloc(10);
	printf("k\t %p\t //动态分配的内存\n", k);
    
    free(k);
    system("pause");
	return 0;
}
