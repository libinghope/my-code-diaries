#include <stdio.h>
#include <stdlib.h>

//extern int a;声明一个变量，这个变量在别的文件中已经定义了，
//这里只是声明，而不是定义。
extern int va;
extern int getVa();
extern int getVa2();
int main(int argc, char* argv[]){
    /*
	允许在不同的函数中使用相同的变量名，它们代表不同的对象，
    分配不同的单元，互不干扰。
	同一源文件中,允许全局变量和局部变量同名，在局部变量的作用域内，
    全局变量不起作用。
	所有的函数默认都是全局的，意味着所有的函数都不能重名，
    但如果是staitc函数，那么作用域是文件级的，所以不同的文件static函数名是可以相同的。
    */
    printf("va = %d\n", va);
    printf("getVa() = %d\n", getVa());
    printf("getVa2() = %d\n", getVa2());


    system("pause");
    return 0;
}