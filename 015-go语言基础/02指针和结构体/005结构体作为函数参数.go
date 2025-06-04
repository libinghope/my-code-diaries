package main

import "fmt"

type person struct {
	id int
	name string
	score int
	sex string
}

func test(s person){

	//fmt.Println(s.name)
	//fmt.Println(s.score)
	//fmt.Println(s.sex)
	s.name="李逵"
}

func main0601() {

	stu:=person{101,"宋江",9,"男"}
	//结构体作为函数参数  值传递
	test(stu)


	fmt.Println(stu)

}

//所有的切片都属于地址传递
func test1(stu []person){

	stu[0].name="晁盖"

}
func main(){
	//结构体切片
	stus:=[]person{person{101,"宋江",9,"男"},
	person{102,"卢俊义",99,"男"}}
	//为切片添加信息
	stus=append(stus,person{103,"吴用",88,"男"})
	//结构体切片作为函数参数是地址传递
	//结构体数组作为函数参数是值传递
	test1(stus)

	fmt.Println(stus)
}