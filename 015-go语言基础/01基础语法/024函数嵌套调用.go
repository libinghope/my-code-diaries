package main

import "fmt"

func test2(a int, b int) {
	sum := a + b
	fmt.Println(sum)
}
func test1(a int, b int) {
	test2(a, b)
}

//所有的函数都是全局函数 可以被项目中所有文件使用  在项目中函数名是唯一的
func main02401() {
	test1(10, 20)

}

func test3(a ...int) {
	//如果函数参数为不定参  传递方式为a[0:]...
	test4(a[0:]...)
	//test4(a[2:]...)
	//test4(a[:2]...)
	test4(a[1:3]...)
}
func main02403() {
	test3(1, 2, 3, 4)
	test3(5, 6, 7, 8)
}

//函数的作用域是全局的  可以在项目中任意文件使用 不需要在意先后顺序
func test4(b ...int) {
	for i := 0; i < len(b); i++ {
		fmt.Println(i, b[i])
	}
}
