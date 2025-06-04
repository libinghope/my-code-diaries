#include<stdio.h>
//知识点
/* 1、C语言共有32个关键字
数据类型关键字:char,short,int,long,float,double,unsigned,signed,struct,union,enum,void
控制语句关键字:if,else,switch,case,default,fro ,do,while,break,continue,goto,return
存储类型关键字:auto,extern,register,static,const
其他关键字:sizeof,typedef,volatile
*/
/*2、常量:在程序的运行过程中，其值永远不变
    通常用const关键字修饰
*/
/*3、变量
    在程序运行过程中，其值可以改变
    变量在使用前必须先定义，定义变量前必须有相应的数据类型

    变量(标识符)命名规则：
    标识符不能是关键字
    标识符只能由字母、数字、下划线组成
    第一个字符必须为字母或下划线
    标识符中字母区分大小写

    变量特点：
    变量在编译时为其分配相应的内存空间
    可以通过其名字和地址访问相应内存
*/

int main(){

    //extern 关键字只做声明，不能做任何定义，
	//声明一个变量a，a在这里没有建立存储空间
	extern int a;
	a = 10;	//err, 没有空间，就不可以赋值

	int b = 10;	//定义一个变量b(b就是标识符)，b的类型为int，b赋值为10
    return 0;
}