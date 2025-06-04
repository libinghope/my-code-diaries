package main

import "fmt"

type Student struct {

	name string
	id int
	age int
	sex string
}
func main0701() {
	//定义结构体变量
	//var 结构体名 结构体数据类型

	//var stu Student=Student{id:101,name:"多啦A梦",age:100,sex:"男"}
	//结构体变量.成员=值

	//定义结构体指针指向变量的地址
	//var p *Student
	////结构体指针指向结构体变量地址
	//p=&stu
	//p1:=&stu
	//p2:=&stu.name
	//
	//fmt.Printf("%T\n",p1)//*Student
	//fmt.Printf("%T\n",p2)//*int
	//
	//fmt.Printf("%T",p)
	//fmt.Printf("%p\n",&stu)
	//fmt.Printf("%p\n",&stu.id)
	//
	//fmt.Printf("%p\n",&stu)
	////结构体成员地址
	//fmt.Printf("%p\n",&stu.name)
	//fmt.Printf("%p\n",&stu.id)
	//fmt.Printf("%p\n",&stu.age)
	//fmt.Printf("%p\n",&stu.sex)
}
func main0702(){
	var stu Student=Student{id:101,name:"多啦A梦",age:100,sex:"男"}

	var p *Student
	p=&stu

	//通过结构体指针间接操作结构体成员
	//(*p).name="大熊"
	//通过指针可以直接操作结构体成员
	p.name="静香"
	p.age=18
	p.sex="女"

	fmt.Println(stu)
}

func main(){

	//结构体切片
	var stu []Student=make([]Student,3)

	p:=&stu//*[]Student  //结构体切片指针
	//stu[0]=Student{"小猪佩奇",1,10,"女"}
	(*p)[0]=Student{"小猪佩奇",1,10,"女"}
	(*p)[1]=Student{"野猪佩奇",2,15,"女"}
	(*p)[2]=Student{"猪刚鬣",3,1000,"男"}

	//append在切片长度后添加数据
	*p=append(*p,Student{"小猪佩奇",1,10,"女"})

	//fmt.Printf("%T\n",p)
	//fmt.Println(stu)

	for i := 0; i<len(*p);i++  {
		fmt.Println((*p)[i])
	}
}