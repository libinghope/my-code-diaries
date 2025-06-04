#include<stdio.h>
//知识点
/*1、数据类型，编译器据此(变量所属数据类型)来分配内存空间
    a、基本类型:整型(int,short,long，longlong),字符型(char)，实型又叫浮点型(float,double)
    b、构造类型(也有人称引用类型):数据，结构体，联合体，枚举
    c、指针类型: int *,char*等
*/
/*2、数据类型所占内存空间的大小可以用sizeof运算符计算
sizeof不是函数，所以不需要包含任何头文件就可以使用
sizeof的返回值是size_t,在32位操作系统中就是unsigned int;
*/

/*有符号(就是分正负号)数与无符号数的区别
有符号数是最高位为符号位，0代表正数，1代表负数。
无符号数最高位不是符号位，而就是数的一部分，无符号数不可能是负数。

当我们写程序要处理一个不可能出现负值的时候，一般用无符号数，这样可以增大数的表达最大值。
数据类型		占用空间	取值范围
short      		2字节	-32768 到 32767 (-215 ~ 215-1)
int		   		4字节	-2147483648 到 2147483647 (-231 ~ 231-1)
long	   		4字节	-2147483648 到 2147483647 (-231 ~ 231-1)
unsigned short	2字节	0 到 65535 (0 ~ 216-1)
unsigned int	4字节	0 到 4294967295 (0 ~ 232-1)
unsigned long	4字节	0 到 4294967295 (0 ~ 232-1)
*/


int main(){
	//整型变量的输入方式
	int aa;
	printf("请输入aa的值：");

	//不要加“\n”
	scanf("%d", &aa);

	 printf("aa = %d\n", aa); //打印aa的值

	int a;//定义一个int型(整型)变量a
	int b = sizeof(a);//sizeof得到a占用内存的大小，单位：字节
	printf("b = sizeof(a) = %d\n", b);

	size_t c = sizeof(a);
	printf("c = %u\n", c);//用无符号数的方式输出c的值

    //int数据的定义和不同进制下的输出方式
    int a1 = 123;	//定义变量a，以10进制方式赋值为123
	int b1 = 0567;	//定义变量b，以8进制方式赋值为0567
	int c1 = 0xabc;	//定义变量c，以16进制方式赋值为0xabc

	printf("a1 = %d\n", a1);
	printf("8进制：b1 = %o\n", b1);
	printf("10进制：b1 = %d\n", b1);
	printf("16进制：c1 = %x\n", c1);
	printf("16进制：c1 = %X\n", c1);
	printf("10进制：c1 = %d\n", c1);

	unsigned int d = 0xffffffff; //定义无符号int变量d，以16进制方式赋值
	printf("有符号方式打印：d = %d\n", d);
	printf("无符号方式打印：d = %u\n", d);

	unsigned short a2 = 20u;
	unsigned int b2 = 20u;
	unsigned long c2= 20ul; 
	unsigned long long d2 = 20ull; 

	//格式化输出
	printf("unsigned short a2 = %hu\n", a2);
	printf("unsigned int b2 = %u\n", b2);
	printf("unsigned long c2 = %lu\n", c2);
	printf("unsigned long long d2 = %llu\n", d2);
    
    return 0;
}