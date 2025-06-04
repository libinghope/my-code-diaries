// c语言代码：C编译器可以编译通过，C++编译器会出错
//i没有写类型，可以是任意类型

// int fun1(i){
// 	printf("%d\n", i);
// 	return 0;
// }

//i没有写类型，可以是任意类型
// int fun2(i){
// 	printf("%s\n", i);
// 	return 0;
// }

//没有写参数，代表可以传任何类型的实参
int fun3(){ 
	printf("fun33333333333333333\n");
	return 0;
}

//C语言，如果函数没有参数，建议写void，代表没有参数
int fun4(void){
	printf("fun4444444444444\n");
	return 0;
}

// g(){
// 	return 10;
// }
/*
int main(){

	fun1(10);
	fun2("abc");
	fun3(1, 2, "abc");
	printf("g = %d\n", g());

	return 0;
}*/
// 	在C语言中，int fun() 表示返回值为int，接受任意参数的函数，int fun(void) 表示返回值为int的无参函数。
// 	在C++ 中，int fun() 和int fun(void) 具有相同的意义，都表示返回值为int的无参函数。
typedef enum COLOR{ GREEN, RED, YELLOW } color;
#include<iostream>
int main(){//在C++中，不同类型的变量一般是不能直接赋值的，需要相应的强转。
	color mycolor = GREEN;
	// mycolor = 10;
	printf("mycolor:%d\n", mycolor);
	// char* p = malloc(10);
	return EXIT_SUCCESS;
}

