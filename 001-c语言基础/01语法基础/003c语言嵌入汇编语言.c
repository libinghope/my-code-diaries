#include<stdio.h>
#include<stdlib.h>
/* c/c++语言可以嵌入汇编代码
 理解汇编需要掌握计算机组成原理等课程
 计算机能执行的必须是机器码(可执行程序)
 C/C++代码编译成可执行程序经过4步：
1）预处理：宏定义展开、头文件展开、条件编译等，同时将代码中的注释删除，这里并不会检查语法
2）编译：检查语法，将预处理后文件编译生成汇编文件
3）汇编：将汇编文件生成目标文件(二进制文件)
4）链接：C语言写的程序是需要依赖各种库的，所以编译之后还需要把库链接到最终的可执行程序中去
gcc的处理流程如下:
    预处理：gcc -E hello.c -o hello.i
    编  译：gcc -S hello.i -o hello.s
    汇  编：gcc -c hello.s -o hello.o
    链  接：gcc    hello.o -o hello_elf
 */
int main(){
    // 定义三个整数
    int a = 10;
    int b = 99;
    int c = 999;
    //以下是visual c++嵌入汇编的方法,相当于c=a+b
    // __asm
    // {
    //     mov a,3
    //     mov b,4
    //     mov eax,a
    //     add eax,b
    //     mov c,eax
    // }
    //printf("a=%d, c = %d; b = %d\n", a, c, b);

    //以下是gcc嵌入汇编的方式，相对来说比较复杂
    asm("movl %1, %%eax; movl %%eax, %0; " :"=r"(b)  :"r"(a)  :"%eax");
    printf("c = %d; b = %d\n", c, b);

    system("pause");
    return 0;
}