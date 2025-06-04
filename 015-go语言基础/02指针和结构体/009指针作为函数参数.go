package main

import "fmt"

//func swap(a int, b int) {
//	a, b = b, a
//}
//函数参数为指针类型
func swap(a *int, b *int) {

	//*a  值
	//*a, *b = *b, *a
	temp:=*a
	*a=*b
	*b=temp
}

func main() {

	a := 10
	b := 20
	//不能交换a b 的值  值传递
	//swap(a,b)
	//指针作为函数参数是地址传递
	swap(&a, &b)

	fmt.Println(a)
	fmt.Println(b)
}
