package main

import "fmt"

//在函数外部定义结构体  作用域是全局的
//type 结构体名 struct{
//	结构体成员列表
//}

type Student struct {
	id 		int
	name	string
	sex		string
	age 	int
	addr 	string
}


func main() {

	//通过结构体名  定义结构体变量
	//var s Student
	////结构体变量名.成员名
	//s.id=101
	//s.name="张飞"
	//s.sex="男"
	//s.age=28
	//s.addr="北京燕郊"
	//
	//fmt.Println(s)

	//var s Student=Student{101,"关羽","男",29,"山西运城"}
	s:=Student{age:30,id:103,name:"刘备",addr:"巴蜀",sex:"男"}
	fmt.Println(s.id)
	fmt.Println(s.name)
	fmt.Println(s.sex)
	fmt.Println(s.age)
	fmt.Println(s.addr)
}
