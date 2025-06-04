package main

import "fmt"
//
//func add(a,b int) int{
//	return a+b
//}
//1、定义函数类型
//2、为已存在的数据类型起别名
type Int int //1、预处理 2、编译 3、汇编 4、链接

//方法
//func (方法接收者)方法名(参数列表)返回值类型
func (a Int)add(b Int)Int{
	return a+b
}

func main06() {
	//result:=add(10,20)
	//根据数据类型 绑定方法
	var a Int=10
	value:=a.add(20)
	//var b Int
	fmt.Println(value)


}
