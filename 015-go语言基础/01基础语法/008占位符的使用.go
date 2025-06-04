package main

import "fmt"

func main0209() {
	//var a int64 =10
	a := 10 //int
	fmt.Printf("%d\n", a)
	//var b float64 =10
	b := 10.0 //float64
	//b:=10//int
	fmt.Printf("%f\n", b)
	var c bool = true
	fmt.Printf("%t\n", c)
	var d byte = 'A'
	fmt.Printf("%c\n", d)
	var e string = "hello"
	fmt.Printf("%s\n", e)

	fmt.Printf("%p\n", &a)

	//%T  打印变量对应的数据类型
	fmt.Printf("%T\n", a)
	fmt.Printf("%T\n", b)
	fmt.Printf("%T\n", c)
	fmt.Printf("%T\n", d)
	fmt.Printf("%T\n", e)
	//%% 会打印一个%
	fmt.Printf("35%%")
}
func maintest() {
	//计算机能够识别的进制  二进制 八进制 十进制 十六进制

	a := 123   //十进制数据
	b := 0123  //八进制数据 以0开头的数据是八进制
	c := 0xabc //十六进制  以0x开头的数据是十六进制
	//go语言中不能直接表示二进制数据

	//fmt.Println(a)
	//fmt.Println(b)
	//fmt.Println(c)
	//%b 占位符 表示输出一个二进制数据
	//fmt.Printf("二进制值为：%b\n",a)
	//fmt.Printf("二进制值为：%b\n",b)
	//fmt.Printf("二进制值为：%b\n",c)
	//%o 占位符 表示输出一个八进制数据
	//fmt.Printf("%o\n",a)
	//fmt.Printf("%o\n",b)
	//fmt.Printf("%o\n",c)
	//%x %X 占位符 表示输出一个十六进制数据
	fmt.Printf("%X\n", a)
	fmt.Printf("%X\n", b)
	fmt.Printf("%X\n", c)
	s := ' '
	fmt.Printf("%T", s)
}
