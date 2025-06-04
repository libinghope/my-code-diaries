#include<stdio.h>
/*
字符串是内存中一段连续的char空间，以'\0'(数字0)结尾。
字符串常量是由双引号括起来的字符序列，如“China”、"abcd"、“C programfiles”，“$12.5”等都是合法的字符串常量。

字符串常量与字符常量的不同：
'a'表示字符常量a, 
"a"表示字符串常量a
每个字符串的结尾，编译器会自动的添加一个结束标志位'\0'，即 "a" 包含两个字符'a'和’\0’。
*/

int main(){
	int a = 100;
	printf("a = %d\n", a);//格式化输出一个字符串
	printf("%p\n", &a);//输出变量a在内存中的地址编号
	printf("%%d\n");

	char c = 'a';
	putchar(c);//putchar只有一个参数，就是要输出的char
	long a2 = 100;
	printf("%ld, %lx, %lo\n", a2, a2, a2);

	long long a3 = 1000;
	printf("%lld, %llx, %llo\n", a3, a3, a3);

	int abc = 10;
	printf("abc = '%6d'\n", abc);
	printf("abc = '%-6d'\n", abc);
	printf("abc = '%06d'\n", abc);
	printf("abc = '%-06d'\n", abc);

	double d = 12.3;
	printf("d = \' %-10.3lf \'\n", d);

    //------------------
    char ch1;
    char ch2;
    char ch3;
	int a1;
	int b1;

	printf("请输入ch1的字符：");
	ch1 = getchar();
	printf("ch1 = %c\n", ch1);

	getchar(); //测试此处getchar()的作用

	printf("请输入ch2的字符：");
	ch2 = getchar();
	printf("\'ch2 = %ctest\'\n", ch2);

	getchar(); //测试此处getchar()的作用
	printf("请输入ch3的字符：");
	scanf("%c", &ch3);//这里第二个参数一定是变量的地址，而不是变量名
	printf("ch3 = %c\n", ch3);

	printf("请输入a的值：");
	scanf("%d", &a1);
	printf("a1 = %d\n", a1);

	printf("请输入b的值：");
	scanf("%d", &b1);
	printf("b1 = %d\n", b1);

    return 0;
}