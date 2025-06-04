package main

import "fmt"

//除法运算符
func main01101() {
	a := 10 //int
	b := 0  //int
	//整型数据相除结果为整型
	//除数不能为0
	c := a / b
	fmt.Println(c)
}

//取余运算符
func main01102() {
	a := 10
	b := 2
	//取余运算符  取模运算符
	//取余运算符只能用于整型数据
	//取余运算符除数不能为0
	c := a % b
	fmt.Println(c)
}

//自增自减运算符
func main01103() {
	a := 10
	//a=a+1
	//++ --只能写在变量的后面 叫做后自增后自减
	//a++//自增运算符
	//a--//自减运算符
	//不能将自增自减运用在表达式中
	//b=a--//err
	fmt.Println(a)
	//fmt.Println(b)
}
