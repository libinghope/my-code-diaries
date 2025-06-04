package main

import "fmt"

//函数定义
//func 函数名(函数参数列表){
//	代码体 程序体 函数体
//}
//变量名 数据类型  如果有多个参数中间用逗号分隔
//先定义后调用
//函数定义
//在函数定义过程中 函数的参数称为形参 形式参数
func add(a int, b int) {
	sum := a + b
	fmt.Println(sum)
}
func main02101() {

	//函数调用
	a1 := 10
	b1 := 20
	//在函数调用过程中 有具体的值成为实参  实际参数
	add(a1, b1)
	//函数可以重复调用
	add(1, 2)

}

func swap(a int, b int) {
	//a,b=b,a
	temp := a
	a = b
	b = temp

	fmt.Println(a, b)
}
func main0702() {

	a := 10
	b := 20
	//形参和实参是不同的存储单元 在函数调用过程中 不会相互影响
	//在函数调用中使用的是实参  在函数定义中使用的形参
	swap(a, b)
	//a和b的值能交换吗？？
	//fmt.Println(a,b)

}
