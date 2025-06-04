#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1. 按位取反 ~
void test01()
{
	int number = 2; //010   101  负数使用补码存储 110 + 1 ，111  -3
	printf("~number : %d\n", ~number);
}

//2. 位与 &
void test02()
{
	int number = 332;
	if ((number & 1) == 0)
	{
		printf("%d是偶数!\n",number);
	}
	else
	{
		printf("%d是奇数!\n",number);
	}

	//number = number & 0;
	number &= 0;
	printf("number:%d\n", number);
}

//3. 位或 |
void test03()
{
	int num1 = 5;
	int num2 = 3;

	printf("num1 | num2 = %d\n", num1 | num2);
}

//4 位异或 ^
void test04()
{
	int num1 = 5;
	int num2 = 9;

#if 0
	int temp = num1;
	num1 = num2;
	num2 = temp;
#endif

	printf("num1:%d num2:%d\n", num1, num2);

	num1 = num1 ^ num2;
	num2 = num1 ^ num2;
	num1 = num1 ^ num2;


	//num1 = num1 ^ num2;
	//num2 = num1 ^ num2;
	//num1 = num1 ^ num2;

	printf("num1:%d num2:%d\n",num1,num2);

}

//左移运算符 左移几位就相当于乘以2的几次方
void test05()
{
	int number = 20;
	printf("number = %d\n" , number <<= 2);
	printf("number = %d\n", number >>= 1);
}


int main(){

	//test01();
	//test02();
	//test03();
	//test04();
	test05();

	system("pause");
	return EXIT_SUCCESS;
}