package main

import "fmt"

var pp **int
func main() {
	a:=10
	p:=&a
	pp:=&p//二级指针  二级指针存储一级指针的地址
	p3:=&pp//三级指针 存储二级指针的地址
	//fmt.Println(p)
	//fmt.Println(&p)

	//一级指针的值
	//fmt.Println(*pp)
	//fmt.Println(p)
	//fmt.Println(&a)
	//变量a 的值
	fmt.Println(*p3)
	fmt.Println(**pp)
	fmt.Println(*p)
	fmt.Println(a)
	//fmt.Printf("%T\n",a)
	//fmt.Printf("%T\n",p)
	//fmt.Printf("%T\n",pp)
	//fmt.Printf("%T\n",ppp)

}
