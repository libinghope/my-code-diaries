#include<stdio.h>
/* 在C语言中常用的有十进制，二进制，八进制和十六进制
    计算机存储数据使用的是二进制的补码形式
    数据的度量采用字节来表示
    8bit=1Byte,1024Byte=1KB,1024KB=1M,1024M=1G,1024G=1T
*/

int main(){

	int a = 123;		//十进制方式赋值
	int b = 0123;		//八进制方式赋值， 以数字0开头
	int c = 0xABC;	//十六进制方式赋值，0x开头

	//如果在printf中输出一个十进制数那么用%d，八进制用%o，十六进制是%x
	printf("十进制：%d\n",a );
	printf("八进制：%o\n", b);	//%o,为字母o,不是数字
	printf("十六进制：%x\n", c);
    return 0;
}