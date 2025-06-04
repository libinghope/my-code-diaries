package main

import "fmt"

func test1(){
	fmt.Println("hello world1")
}
func test2(){
	//fmt.Println("hello world2")
	//可以在程序中直接调用panic 调用后程序会终止执行
	panic("hello world2")
	//print 和println 是对错误信息进行处理的  不建议在程序中打印数据时使用
	//print()
	//println()
}
func test3(){
	fmt.Println("hello world3")
}

func main() {
	test1()
	test2()
	test3()
}
