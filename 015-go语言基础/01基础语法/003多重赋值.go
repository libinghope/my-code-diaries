package main

import "fmt"

func main0301(){
	//var a int =10
	//a:=10
	//格式 变量1，变量2:=值1,值2
	a,b,c,d:=10,20,30,40
	fmt.Println(a,b,c,d)
}

func main0302(){
	a,b:=10,20

	//交换a b 的值
	////通过自动推到类型为temp赋值
	//temp:=a
	//a=b
	//b=temp

	//加减计算
	//a=a+b
	//b=a-b
	//a=a-b

	//交换变量的值
	a,b=b,a

	fmt.Println(a)
	fmt.Println(b)
}
//匿名变量
func main0303()  {
	_,b,_,d:=1,2,3,4

	//fmt.Println(_)
	fmt.Println(b)
	fmt.Println(d)
	//fmt.Println(_)
}