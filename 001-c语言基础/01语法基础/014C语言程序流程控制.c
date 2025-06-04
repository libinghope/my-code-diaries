#include<stdio.h>
/*
C语言支持最基本的三种程序运行结构：顺序结构、选择结构、循环结构。
    顺序结构：程序按顺序执行，不发生跳转。
    选择结构：依据是否满足条件，有选择的执行相应功能。
    循环结构：依据条件是否满足，循环多次执行某段代码。

三种结构是可以自身和彼此间嵌套的
*/

int main(){
    //顺序结构,从上向下依次执行
    int a, b;
    a = 10;
    b = 32;
    int c=0;
    c = a + b;
    //-----------------

    //分支结构
    if(a > b){
        printf("a > b的话就执行这行代码\n");
    }

    if(c>b){
        printf("c > b的话就执行这行代码\n");
    }else{
        printf("c <= b的话就执行这行代码\n");
    }

    if(a<b){
        printf("a < b的话就执行这行代码\n");
    }else if(a == b){
        printf("a = b的话就执行这行代码\n");
    }else{
        printf("a > b的话就执行这行代码\n");
    }
    //三目运算符
    c = (a > b ? a : b);//翻译成白话，a>b的话c=a(冒号前面),否则c=b(冒号后面)

    char c1;
	c1 = getchar();

	switch (c1) //参数只能是整型变量
	{
	case '1':
		printf("OK\n");
		break;//switch遇到break就中断了
	case '2':
		printf("not OK\n");
		break;
	default://如果上面的条件都不满足，那么执行default
		printf("are u ok?\n");
	}

    //循环结构
    int e = 20;
	while (e > 10)//第一次e>10,就执行while后边{}中的内容
	{
		scanf("%d", &e);//根据你的输入来决定是否停止循环
		printf("a = %d\n", e);
	}

    for(int i=0; i<10; i++){
        printf("第%d次for循环\n", i);
    }
	return 0;

}