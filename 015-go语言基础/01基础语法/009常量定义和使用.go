package main

import "fmt"

func maintest0301() {
	//常量定义和使用
	//在程序运行过程中其值不能发生改变的量 成为常量
	//常量的存储位置在数据区
	//栈区 系统为每一个应用程序分配1M空间用来存储变量  在程序运行结束系统会自动释放
	var s1 int = 10
	var s2 int = 20
	//常量的存储位置在数据区 不能通过& 取地址来访问
	const a int = 10

	fmt.Println(&s1)
	fmt.Println(&s2)
	//a=20//常量的值不允许修改

	fmt.Println(a)
}
func maintest0302() {
	//常量一般用大写字母表示
	//根C++没什么区别
	const MAX int = 10
	b := 20
	c := MAX + b
	fmt.Println(c)
	//字面常量
	fmt.Println(123)
	fmt.Println("hello world")
	//硬常量 32
	d := c + 32
	e := "hello"
	e = e + "world"
	fmt.Println(d)
	fmt.Println(e)

}
