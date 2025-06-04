package main

import "fmt"

func main1201() {
	//demo1()
	//局部变量  在函数内部定义的变量  作用域限定于本函数内部 从变量定义到本函数结束有效
	//var 变量名 数据类型 先定义后使用
	//在同一作用域范围内 变量名是唯一的
	//fmt.Printf(a)
	//a:=10
	////匿名内部函数
	//{
	//	//var a int =20
	//	a:=20
	//	fmt.Println(a)
	//}
	//fmt.Println(a)

	//程序中如果出现了相同的变量名 如果本函数有自己的变量 就使用自己的 如果没有上外层寻找变量
	//如果名字相同会采用就进原则 使用自己的变量
	i := 0 //i:=0
	for i := 0; i < 10; i++ {

	}
	fmt.Println(i)

}

//func demo1(){
//	fmt.Println(a)
//}

func main02701() {
	demo2()
	//采用就进原则使用局部变量
	//在局部变量作用域范围内 全局变量不起作用
	a := 234
	fmt.Println(a)
}

//全局变量  在函数外部定义的变量成为全局变量
//全局变量作用域是项目中所有文件
//全局变量在内存中数据区存储 和const定义的常量存储位置都是数据区
var a int = 10 //如果全局变量没有初始值值为0

//全局常量
const b int = 10

func demo2() {

	a = 123
	//const a int =10
	fmt.Println(a)
}
