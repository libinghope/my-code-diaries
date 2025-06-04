package main

import "fmt"

func main03701() {
	s := []int{1, 2, 3, 4, 5}
	//切片名[起始下标:]
	//slice:=s[2:]
	//切片名[:结束位置] 不包含结束位置
	//slice:=s[:2]
	//切片名[起始位置:结束位置]
	//slice:=s[2:5]
	//切片名[起始位置:结束位置:容量]
	slice := s[0:2:2] //大于等于len  小于等于cap  len <= xxx <= cap
	fmt.Println(cap(slice))
	fmt.Println(slice)
}
func main03702() {
	s := []int{1, 2, 3, 4, 5}
	//slice:=s[2:4]//[1 2]
	//
	//slice[1]=123
	//
	//fmt.Println(slice)
	//
	//fmt.Println(s)
	//
	////切片名  本身就是地址
	////一个字节在内存中占8bit（位）
	//fmt.Printf("%p\n",s)
	//fmt.Printf("%p\n",&s[1])
	//fmt.Printf("%p\n",&s[2])
	//fmt.Printf("%p\n",slice)
	//切片名[:]获取切片中所有元素
	slice := s[:]
	fmt.Println(slice)

	news := make([]int, 5)
	copy(news, s)
	fmt.Printf("%p\n", news)
	fmt.Printf("%p\n", s)
}
