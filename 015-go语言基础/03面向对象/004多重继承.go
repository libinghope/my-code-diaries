package main

import "fmt"

type TestA struct {
	name string
	id   int
}
type TestB struct {
	TestA
	sex string
	age int
}

//注意结构体不能嵌套本结构体
//结构体可以嵌套本结构体指针类型  链表
type TestC struct {
	//*TestC  ok
	//TestC//err
	TestB
	score int
}

func main04() {
	var s TestC = TestC{TestB{TestA{"欧罗巴", 10}, "男", 19}, 4}
	//s.score=100
	//s.TestC.score=100
	//s.TestB.TestA.name="姆巴佩"
	//s.name="李四"
	//s.id=201
	//s.sex="男"
	//s.age=20
	//s.score=10

	fmt.Println(s)
}
