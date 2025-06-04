#include "005mystring.h"
/*
运算符重载本质上还是函数，只是这个函数名用操作符代替了而已。
除非真的能带来方便，一般不要重载运算符
这里用定义一个字符串类来使用运算符重载功能
*/
//用g++ 005mystring.cpp 005运算符重载.cpp 可以成功,clang 报错
int main(){
    char * sss = "abcdefg";
    MyString str(sss);
    str.println();
    cout<< str[2]<<endl;
    str + "123456";
    str.println();
    return 0;
}
