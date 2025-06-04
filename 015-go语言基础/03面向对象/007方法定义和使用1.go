package main

import "fmt"

type Stu struct {
	name string
	age  int
	sex  string
}

//方法 值传递
func (s Stu) PrintInfo() {
	fmt.Println(s.name)
	fmt.Println(s.age)
	fmt.Println(s.sex)
}

// 地址传递
func (s *Stu) EditInfo(name string, age int, sex string) {
	//(*s).name=name
	//结构体指针可以直接调用结构体成员
	s.name = name
	s.age = age
	s.sex = sex
	//s.PrintInfo()
}

func main() {
	var s1 *Stu
	s1 = new(Stu)
	s1.EditInfo("薛宝钗", 24, "女")
	//指针可以调用对象结构体的方法
	s1.PrintInfo()
}
func main0701() {

	//var s Stu = Stu{"刘姥姥", 54, "女"}
	////对象.方法
	//s.PrintInfo()

	var s1 Stu = Stu{"王宝钗", 24, "女"}
	s1.PrintInfo()

	//(&s1).EditInfo("林黛玉",16,"女")//ok
	//结构体变量可以直接使用结构体指针对应的方法
	s1.EditInfo("林黛玉", 16, "女")
	s1.PrintInfo()
}
