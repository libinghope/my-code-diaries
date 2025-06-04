#include<iostream>
using namespace std;

int arr[10];
bool is_array_full(int* arr){
    return 1;
}

void push_array(int a){
    if(is_array_full(arr)){
        throw "数组满了，不能再push了 ！";
    }
}
/*
如上面的push_array方法向数组中压入数据，当数组满的时候如何表示
如果用返回值不同代表满了，有可能造成歧义，当返回0，0到底代表什么,下标0?满了？

	若有异常则通过throw操作创建一个异常对象并抛出。
	将可能抛出异常的程序段放到try块之中。
	如果在try段执行期间没有引起异常，那么跟在try后面的catch字句就不会执行。
	catch子句会根据出现的先后顺序被检查，匹配的catch语句捕获并处理异常(或继续抛出异常)
	如果匹配的处理未找到，则运行函数terminate将自动被调用，其缺省功能调用abort终止程序。
	处理不了的异常，可以在catch的最后一个分支，使用throw，向上抛。
*/

int main(){
    try{
        //对可能抛出异常的代码段进行处理
        push_array(1);
    }catch(int e){
        cout<<"数组满了"<<endl;
    }
    return 0;
}

