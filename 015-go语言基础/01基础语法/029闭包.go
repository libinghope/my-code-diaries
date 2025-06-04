package main

import "fmt"

//函数在调用结束会从内存中销毁
func test111(a int) {
	a++
	fmt.Println(a)
}

func main02901() {
	a := 0
	for i := 0; i < 10; i++ {
		//test1(a)
		fmt.Println(a)
	}
}

//可以通过匿名函数和闭包 实现函数在栈区的本地化
func test2222() func() int {
	var a int

	return func() int {
		a++
		return a
	}
}
func main02902() {
	//将test2函数类型赋值给f
	//f:=test2
	//函数调用 将test2的返回值给f
	//f := test2()
	//var a int
	//f:=func()  int{
	//	a++
	//	return a
	//}
	for i := 0; i < 10; i++ {
		//fmt.Println(f())
	}
	//fmt.Printf("%T",f)
}
