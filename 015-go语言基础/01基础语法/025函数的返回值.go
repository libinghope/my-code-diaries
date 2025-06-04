package main

import "fmt"

//func  函数名（形参列表）返回值类型列表{代码体}
//func sub(a int ,b int ) int {
//	sum:=a-b
//	//return 表示函数的结束  return 后面的代码不会执行 同时return也会将函数的返回值传递给主调函数
//	return sum
//	fmt.Println("helloworld")
//	fmt.Println("helloworld")
//	fmt.Println("helloworld")
//	return 0
//}
//return可以写一个表达式 将表达式的结果作为返回值
//func sub(a int, b int) int {
//	return  a-b
//}
func sub(a int, b int) (sum int) {
	sum = a - b
	return
}
func main1001() {
	var value int
	value = sub(10, 20)

	fmt.Println(value)
}

//函数多个返回值
//如果函数没有参数在函数调用时()必须写
func test5() (a int, b int, c int) {
	//多重赋值
	a, b, c = 1, 2, 3
	return
}
func main02501() {
	//函数的返回值可以为主调函数赋值  可以通过返回值改变实参数据
	//a,b,c:=test5()
	//如果函数有多个返回值 但是不使用返回值 可以用匿名变量接收数据
	a, _, c := test5()
	fmt.Println(a)
	//fmt.Println(b)
	fmt.Println(c)
}
