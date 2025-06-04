package main

import "fmt"

type person struct {
	name string
	age int
	sex string
}

//结构体嵌套结构体
type Student struct {
	//通过匿名字段实现继承操作
	person //结构体名称作为结构体成员
	id int
	score int
}

func main01() {
	var stu Student = Student{person{"张三丰",190,"男"},101,100}

	//stu.id=101
	////结构体名称.父类成员信息
	//stu.name="张三"
	////stu.person.name="张三"
	//stu.score=100
	//stu.sex="男"
	//stu.age=18

	fmt.Println(stu)

}
