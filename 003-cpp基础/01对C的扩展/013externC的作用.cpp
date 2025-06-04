/*
假设有三个文件  fun.h,fun.c, main.cpp
fun.c中定义了fun1函数，
为了能在main(c++)中调用fun.c(c语言)中的函数，
可以 使用extern c的方式.
*/
#include<iostream>
using namespace std;

#if 0

	#ifdef __cplusplus//判断是C还是C++
	extern "C" {
		#if 0
			void func1();
			int func2(int a, int b);
		#else
			#include"MyModule.h"
		#endif
	}

	#endif

#else

	extern "C" void func1();
	extern "C" int func2(int a, int b);

#endif

int main(){
	func1();
	cout << func2(10, 20) << endl;
	return EXIT_SUCCESS;
}
