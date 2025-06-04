#include <stdlib.h>
#include <stdio.h>


int main(){
    //数组名字是数组的首元素地址，但它是一个常量：
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	printf("a = %p\n", a);
	printf("&a[0] = %p\n", &a[0]);
	//a = 10; //err, 数组名是常量，不能修改

    //用指针操作数组
	int i = 0;
	int n = sizeof(a) / sizeof(a[0]);
	
	for (i = 0; i < n; i++)
	{
		//printf("%d, ", a[i]);
		printf("%d, ", *(a+i));
	}
	printf("\n");

	int *p = a; //定义一个指针变量保存a的地址
	for (i = 0; i < n; i++)
	{
		p[i] = 2 * i;
	}

	for (i = 0; i < n; i++)
	{
		printf("%d, ", *(p + i));
	}
	printf("\n");


    system("pause");
    return 0;
}