package main

import "fmt"

func main0401() {
	//输出格式 Println  打印数据时自带换行
	/*
		fmt.Println("hello")
		fmt.Println(10)
		fmt.Println(3.14)
	*/
	//输出格式 Print  打印数据时不带换行
	//fmt.Print("hello")
	//fmt.Print(10)
	//fmt.Print(3.14)
	a := 123456
	b := 3.14159
	//%d 占位符 表示输出一个整型数据
	//%f 占位符 表示输出一个浮点型数据
	//\n 表示转义字符 相当于换行符
	fmt.Printf("==%3d==\n", a)
	//%f占位符默认保留六位小数 %.3f表示小数点后面保留三位小数 会对第四位四舍五入
	fmt.Printf("%.4f\n", b)
}

func main01() {
	//bool布尔  string字符串 byte字符
	//声明bool类型变量 默认值为 false   true
	var a bool
	a = true
	//fmt.Println(a)
	//%t 占位符 表示输出一个布尔类型数据
	fmt.Printf("%t\n", a)
	var b string
	b = "性感荷官在线发牌"
	//%s 占位符 表示输出一个字符串类型数据
	fmt.Printf("%s\n", b)
	var c byte
	c = 'a'
	//字符型变量对应的ASCII码值
	//fmt.Println(c)
	//%c 占位符 表示输出一个字符类型数据
	fmt.Printf("%c", c)
}
