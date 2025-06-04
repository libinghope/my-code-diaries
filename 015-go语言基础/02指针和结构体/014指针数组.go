package main

import "fmt"

func main() {

	//var arr [3]int ->int
	//指针数组
	var arr [3]*int  //->*int
	a:=10
	b:=20
	c:=30

	arr[0]=&a
	arr[1]=&b
	arr[2]=&c


	//fmt.Println(arr)
	//fmt.Printf("%p\n",&a)
	//fmt.Printf("%p\n",&b)
	//fmt.Printf("%p\n",&c)


	//通过指针数组改变变量的值
	//*arr[1]=2
	//
	//fmt.Println(b)

	//变量指针数组对应的内存空间的值
	for i := 0; i < len(arr); i++ {
		fmt.Println(*arr[i])
	}

}
