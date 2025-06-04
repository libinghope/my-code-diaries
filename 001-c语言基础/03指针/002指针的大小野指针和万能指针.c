#include <stdio.h>
#include <stdlib.h>

int main(){

    /*
    使用sizeof()测量指针的大小，得到的总是：4或8
	sizeof()测的是指针变量指向存储地址的大小
	在32位平台，所有的指针（地址）都是32位(4字节)
	在64位平台，所有的指针（地址）都是64位(8字节)
    */
    int *p1;
	int **p2;
	char *p3;
	char **p4;
	printf("sizeof(p1) = %d\n", sizeof(p1));
	printf("sizeof(p2) = %d\n", sizeof(p2));
	printf("sizeof(p3) = %d\n", sizeof(p3));
	printf("sizeof(p4) = %d\n", sizeof(p4));
	printf("sizeof(double *) = %d\n", sizeof(double *));


    /*
    指针变量也是变量，是变量就可以任意赋值，不要越界即可（32位为4字节，64位为8字节），
    但是，任意数值赋值给指针变量没有意义，因为这样的指针就成了野指针，
    此指针指向的区域是未知(操作系统不允许操作此指针指向的内存区域)。
    所以，野指针不会直接引发错误，操作野指针指向的内存区域才会出问题。
    */
   	int a = 100;
	int *p;
	p = a; //把a的值赋值给指针变量p，p为野指针， ok，不会有问题，但没有意义

	p = 0x12345678; //给指针变量p赋值，p为野指针， ok，不会有问题，但没有意义

	*p = 1000;  //操作野指针指向未知区域，内存出问题，err
    /*
    但是，野指针和有效指针变量保存的都是数值，为了标志此指针变量没有
    指向任何变量(空闲可用)，C语言中，可以把NULL赋值给此指针，
    这样就标志此指针为空指针，没有任何指针。
    */
   	int *ptr = NULL;

    //NULL是一个值为0的宏常量：
    #define NULL    ((void *)0)

    //void *指针可以指向任意变量的内存空间：万能指针
    void *p5 = NULL;

	int n = 10;
	p5 = (void *)&a; //指向变量时，最好转换为void *

	//使用指针变量指向的内存时，转换为int *
	*( (int *)p ) = 11;
	printf("a = %d\n", n);



    system("pause");
    return 0;
}