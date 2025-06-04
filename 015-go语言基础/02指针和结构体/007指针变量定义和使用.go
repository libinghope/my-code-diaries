package main

import "fmt"

func main0901() {
	var a int = 123

	//定义整型指针变量 指向a的地址
	//指针类型定义
	//var 指针 *数据类型  一级指针
	var p *int
	//将a的地址赋值给指针变量p
	p=&a


	//通过指针变量 间接访问变量对应的内存空间
	*p=345
	fmt.Println(a)
	//fmt.Println(*p)
	//fmt.Println(p)
	//fmt.Println(&a)


}
func main(){
	//a:=10
	//p:=&a
	//
	//*p=123
	//fmt.Println(a)
	//fmt.Printf("%T",p)
	//声明了一个指针 默认值为nil（空指针 值为0）指向了内存地址编号为0 的空间
	//0-255为系统占用 不允许用户进行读写操作
	var p *int//空指针
	//p=a//err
	//p=0xc042058080//野指针  指针变量指向了一个未知的空间
	//访问野指针和空指针对应的内存空间都会报错
	//*p=123
	//*p=123//err
	fmt.Println(p)
}