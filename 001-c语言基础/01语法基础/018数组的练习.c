#include<stdio.h>
#include<stdlib.h>

int main()
{
    //练习1，求出数组的最大值
	int a[] = {  1, -2, 3,- 4, 5, -6, 7, -8, -9, 10 };//定义一个数组，同时初始化所有成员变量

	int i = 0;
	int max = a[0];
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	printf("数组中最大值为：%d\n", max);

    //练习2，数组元素的逆置
    int a1[] = {  1, -2, 3,- 4, 5, -6, 7, -8, -9, 10 };
    i = 0;
    int j = sizeof(a1) / sizeof(a1[0]) -1;
    int temp = 0;
    while(i < j){
        temp = a1[i];
        a1[i] = a1[j];
        a1[j] = temp;
        ++i;
        ++j;
    }
    //打印出逆序后的数组
    for (i = 0; i < sizeof(a1) / sizeof(a1[0]); i++)
	{
		printf("%d ", a1[i]);
	}
	printf("\n");


    //冒泡排序算法
    int arr[] = {  1, -2, 3,- 4, 5, -6, 7, -8, -9, 10 };
    int arr_len = sizeof(arr) / sizeof(int);
    int tmp = 0;
    for(int i = 0; i < arr_len; i++){
        for(int j =0; j < arr_len -i; j++){
            if(arr[j] > arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp; 
            }
        }
    }
    printf("冒泡排序后的数组:\n");
    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
    
    system("pause");
	return 0;
}
