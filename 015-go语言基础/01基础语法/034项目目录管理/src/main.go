package main

import "userinfo"

//!注意：同一个目录下不能定义不同的package。
/*
建立userinfo包需要跟main包不在一个目录下
第一：不同目录，包名不一致（自定义包）。
第二：main.go中调用userinfo包中的方法时，一定要导包，并且调用的方式是：包名.函数名 的方式
userinfo文件中的函数名首字母必须大写，如果改成小写在main.go中无法进行调用
*/
//全局变量
var num int = 123

//在同级别目录报名要相同
func main() {
	add(10, 20)
	//包名.函数名
	userinfo.Login()
	userinfo.DeleteUser()
	userinfo.SelectUser()

}
