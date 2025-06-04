package main

import "fmt"

type person4 struct{
	name string
	age int
	sex string
}
type student4 struct {
	person4

	score int
}
func (p person4)PrintInfo(){
	fmt.Printf("大家好，我是%s，我今年%d岁，我是%s生\n",p.name,p.age,p.sex)
}
//方法重写  在一个对象中不能出现相同的方法名  方法的接收者 带* 和不带* 表示一个相同的对象
func (s student4)PrintInfo(){
	fmt.Printf("大家好，我是%s，我今年%d岁，我是%s生,我的分数是%d分\n",s.name,s.age,s.sex,s.score)
}
//func (s *student4)PrintInfo(){
//	fmt.Printf("大家好，我是%s，我今年%d岁，我是%s生,我的分数是%d分\n",s.name,s.age,s.sex,s.score)
//}
func main() {
	s:=student4{person4{"张三",11,"男"},19}
	//默认使用子类的方法  采用就进原则
	//调用子类方法
	s.PrintInfo()
	//调用父类方法
	s.person4.PrintInfo()
}
