package main

import "fmt"

type person struct {
	name string
	sex string
	age int
}

type student struct {
	person
	score int
}

type teacher struct {
	person
	subject string
}

func (s *student)SayHello(){
	fmt.Printf("大家好，我是%s，我是%s生，我今年%d岁了，我的成绩是%d分\n",s.name,s.sex,s.age,s.score)
}
func (t *teacher)SayHello(){
	fmt.Printf("大家好，我是%s，我是%s生，我今年%d岁了，我叫的学科是%s\n",t.name,t.sex,t.age,t.subject)
}
//1
//接口定义
//接口定义了规则   方法实现了规则
//接口是虚的    方法是实的
//格式 type  接口名  interface{方法列表}
//方法名（参数列表）（返回值列表）
type Humaner interface {
	//2
	//方法 函数声明 没有具体实现  具体的实现要根据对象不同  实现方式也不同
	//接口中的方法必须有具体的实现
	SayHello()
}
func main() {

	var stu student=student{person{"小明","男",18},100}
	var tea teacher=teacher{person{"法师","女",31},"盗墓"}
	//3
	//定义接口类型
	//接口做了同一的处理 先实现接口  在根据接口实现对应的方法
	//在需求改变时 不需要改变接口 只需要修改方法
	var h Humaner

	//fmt.Println(h.SayHello)
	h=&stu
	h.SayHello()

	fmt.Printf("%p\n",h)
	h=&tea
	h.SayHello()

	fmt.Printf("%p\n",h)


	//stu.SayHello()
	//tea.SayHello()
}
