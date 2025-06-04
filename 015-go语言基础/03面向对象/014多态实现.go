package main

import "fmt"

type person1 struct {
	name string
	sex string
	age int
}

type student1 struct {
	person1
	score int
}

type teacher1 struct {
	person1
	subject string
}

func (s *student1)SayHello(){
	fmt.Printf("大家好，我是%s，我是%s生，我今年%d岁了，我的成绩是%d分\n",s.name,s.sex,s.age,s.score)
}
func (t *teacher1)SayHello(){
	fmt.Printf("大家好，我是%s，我是%s生，我今年%d岁了，我叫的学科是%s\n",t.name,t.sex,t.age,t.subject)
}

//接口实现
type Personer interface {
	SayHello()
}

//多态实现
//多态是将接口类型作为函数参数  多态实现接口的统一处理
func SayHello(p Personer){
	p.SayHello()
}

func main() {

	var p Personer

	p=&student1{person1{"小红","女",10},90}

	//p.SayHello()
	SayHello(p)

	p=&teacher1{person1{"一泓","女",18},"心里辅导"}
	SayHello(p)
}
