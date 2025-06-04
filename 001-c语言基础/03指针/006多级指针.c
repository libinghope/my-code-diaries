#include <stdlib.h>
#include <stdio.h>

//	C语言允许有多级指针存在，在实际的程序中一级指针最常用，其次是二级指针。
//  二级指针就是指向一个一级指针变量地址的指针。
//  三级及以上指针很少会用到
int main(){
    int a = 10;
	int *p = &a; //一级指针
	*p = 100; //*p就是a

	int **q = &p;
	//*q就是p
	//**q就是a

	int ***t = &q;
	//*t就是q
	//**t就是p
	//***t就是a


    system("pause");
    return 0;
}