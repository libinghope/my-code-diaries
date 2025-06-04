#include <iostream>
using namespace std;
/*标准c++的bool类型有两种内建的常量true(转换为整数1)和false(转换为整数0)表示状态。
这三个名字都是关键字。
	bool类型只有两个值，true(1值)，false(0值)
	bool类型占1个字节大小
	给bool类型赋值时，非0值会自动转换为true(1),0值会自动转换false(0)

[c语言中的bool类型]
c语言中也有bool类型，在c99标准之前是没有bool关键字，c99标准已经有bool类型，
包含头文件stdbool.h,就可以使用和c++一样的bool类型。
*/
void test()
{
    cout << sizeof(false) << endl; //为1，//bool类型占一个字节大小
    bool flag = true;              // c语言中没有这种类型
    flag = 100;                    //给bool类型赋值时，非0值会自动转换为true(1),0值会自动转换false(0)
}
int main()
{

    return 0;
}