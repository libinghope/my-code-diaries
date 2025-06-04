#include <stdlib.h>
#include <stdio.h>


int main(){
    int a = 100;
	int b = 200;

    //指向常量的指针
	//修饰*，指针指向内存区域不能修改，指针指向可以变
	const int *p1 = &a; //等价于int const *p1 = &a;
	//*p1 = 111; //err
	p1 = &b; //ok

    //指针常量
	//修饰p1，指针指向不能变，指针指向的内存可以修改
	int * const p2 = &a;
	//p2 = &b; //err
	*p2 = 222; //ok


    system("pause");
    return 0;
}