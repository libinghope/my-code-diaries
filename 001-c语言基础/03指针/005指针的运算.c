#include <stdlib.h>
#include <stdio.h>


int main(){
    /*
    	指针计算不是简单的整数相加
    	如果是一个int *，+1的结果是增加一个int的大小
    	如果是一个char *，+1的结果是增加一个char大小
    */
   	int a;
	int *p = &a;
	printf("%d\n", p);
	p += 2;//移动了2个int
	printf("%d\n", p);

	char b = 0;
	char *p1 = &b;
	printf("%d\n", p1);
	p1 += 2;//移动了2个char
	printf("%d\n", p1);

    //通过指针的移动操作数组元素
    int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int i = 0;
	int n = sizeof(a) / sizeof(a1[0]);

	int *p2 = a1;
	for (i = 0; i < n; i++)
	{
		printf("%d, ", *p2);
		p2++;
	}
	printf("\n");



    system("pause");
    return 0;
}