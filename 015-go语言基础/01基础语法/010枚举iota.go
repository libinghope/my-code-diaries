package main

import "fmt"

func main101() {

	const (
		a = iota //0//静止
		b = iota //1//移动
		c = iota //2//普通攻击
		d = iota
	)

	fmt.Println(a)
	fmt.Println(b)
	fmt.Println(c)
	fmt.Println(d)

	//定义变量 为 状态
	value := a
	fmt.Println(value)
	value = b
	fmt.Println(value)

}

func main1002() {
	//const(
	//    a=iota//0
	//    b//1
	//    c//2
	//    d//3
	//    e//4
	//)

	//如果定义枚举是常量写在同一行值相同 换一行值加一
	//在定义枚举时可以为其赋初始值 但是换行后不会根据值增长
	const (
		a    = 10
		b, c = iota, iota
		d, e
	)

	fmt.Println(a)
	fmt.Println(b)
	fmt.Println(c)
	fmt.Println(d)
	fmt.Println(e)
}
