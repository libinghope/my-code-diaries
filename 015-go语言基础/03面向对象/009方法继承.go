package main

import "fmt"

type person3 struct {
	id   int
	name string
	age  int
	sex  string
}

type student3 struct {
	p     person3 //结构体变量 结构体类型
	//person3
	score int
}
func (p *person3)SayHello(){
	fmt.Println("1大家好，我是",p.name,"我是",p.sex,"生，我今年",p.age)
}
//func (s *student3)SayHello(){
//	fmt.Println("2大家好，我是",s.name,"我是",s.sex,"生，我今年",s.age)
//}
func main() {
	var stu student3=student3{person3{203,"贾玲",18,"女"},100}
	var p person3=person3{203,"贾玲",18,"女"}
	//父类不能继承子类信息
	p.SayHello()
	//var stu student3=student3{100}
	//stu.p.age = 18
	//stu.p.name = "贾玲"
	//stu.p.sex = "女"
	//stu.p.id = 203
	//stu.score = 100
	//子结构体继承父类结构体  允许使用父类结构体成员  允许使用父类的方法
	stu.p.SayHello()
	//fmt.Println(stu)
}
