#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

int main()
{
	int count, *array, n;
	printf("请输入要申请数组的个数:\n");
	scanf("%d", &n);
    /* void *malloc(size_t size);
    功能：在内存的动态存储区(堆区)中分配一块长度为size字节的连续区域，
        用来存放类型说明符指定的类型。分配的内存空间内容不确定，一般使用memset初始化。
    参数：
        size：需要分配内存大小(单位：字节)
    返回值：
    成功：分配空间的起始地址
    失败：NULL
    */
	array = (int *)malloc(n * sizeof (int));
	if (array == NULL)
	{
		printf("申请空间失败!\n");
		return -1;
	}
	//将申请到空间清0
	memset(array, 0, sizeof(int)*n);

	for (count = 0; count < n; count++) /*给数组赋值*/
		array[count] = count;

	for (count = 0; count < n; count++) /*打印数组元素*/
		printf("%2d", array[count]);

	free(array);

    system("pause");
	return 0;
}
