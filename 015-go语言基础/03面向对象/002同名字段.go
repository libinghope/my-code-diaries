package main

import "fmt"

type Person struct {
	name string
	age  int
	sex  string
}
type student struct {
	Person //匿名变量实现继承
	id     int
	name   string
	score  int
}

func main() {
	var stu student = student{Person{"张三疯", 18, "男"}, 102, "张三", 100}
	//采用就进原则 使用子类信息
	//stu.name="张三丰"
	////结构体变量.匿名字段.结构体成员
	////stu.Person.name="张三疯"
	//stu.id=101
	//stu.score=99
	//stu.sex="男"
	//stu.age=18
	fmt.Println(stu.name)
	fmt.Println(stu)

}
