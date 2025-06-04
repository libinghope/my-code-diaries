package main

import "fmt"

//func test(s []int) {
//	s=append(s,4,5,6)
//}

func test(s *[]int){
	*s=append(*s,4,5,6,)
}

func main() {
	s:=[]int{1,2,3}
	fmt.Printf("%p\n",s)
	//切片指针作为函数参数是地址传递  形参可以改变实参的值
	test(&s)

	fmt.Printf("%p\n",s)
	fmt.Println(s)
}
