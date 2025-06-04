#include<iostream>
using namespace std;
/*  c语言全局const会被存储到只读数据段。
c++中全局const当声明extern或者对变量取地址时，
编译器会分配存储地址，变量存储在只读数据段。
两个都受到了只读数据段的保护，不可修改。
    c语言中局部const存储在堆栈区，只是不能通过变量直接修改const只读变量的值，
但是可以跳过编译器的检查，通过指针间接修改const值。
*/

/*C++中
1.	对于基础数据类型，也就是const int a = 10这种，编译器会把它放到符号表中，
不分配内存，当对其取地址时，会分配内存。
2.	对于基础数据类型，如果用一个变量初始化const变量，如果const int a = b,
那么也是会给a分配内存。
3.	对于自定义数据类型，比如类对象，那么也会分配内存。

*/

//编程中尽量用const替代 #define
int main(){
	const int constA = 10;
	int* p = (int*)&constA;
	*p = 300;
	printf("constA:%d\n",constA);
	printf("*p:%d\n", *p);

    return 0;
}