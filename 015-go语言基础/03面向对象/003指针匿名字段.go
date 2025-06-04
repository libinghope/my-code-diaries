package main

import "fmt"

type person1 struct {
	name string
	age  int
	sex  string
}

type student1 struct {
	*person1 //指针匿名字段
	id       int
	score    int
}

func main() {

	var stu student1 = student1{&person1{"小龙女", 38, "女"}, 105, 66}
	//var per=person1{"杨过",35,"男"}
	//stu.person.name
	//将结构体变量 赋值给结构体指针类型
	//stu.person1=&per
	//stu.person1=new(person1)
	//stu.name = "郭襄"
	//stu.person1.name = "郭小姐"
	//stu.id = 101
	//stu.score = 78

	fmt.Println(stu)
	fmt.Println(stu.name)
	fmt.Println(stu.id)
	fmt.Println(stu.score)
}
