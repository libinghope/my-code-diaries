package main

import "fmt"

func test0(s []int) {
	//fmt.Printf("%p\n",s)
	s[2] = 123
}
func main03901() {
	s := []int{1, 2, 3, 4, 5}
	//test(s)
	//fmt.Printf("%p\n",s)
	fmt.Println(s)
}

//BubbleSort2
func BubbleSort2(s []int) {

	for i := 0; i < len(s)-1; i++ {
		for j := 0; j < len(s)-1-i; j++ {
			if s[j] > s[j+1] {
				s[j], s[j+1] = s[j+1], s[j]
			}
		}
	}
}

func main03902() {

	s := []int{9, 1, 5, 6, 7, 3, 10, 2, 4, 8}
	//切片作为函数参数是地址传递 形参可以改变实参的值
	//在实际开发者 建议使用切片代替数组
	//BubbleSort(s)

	fmt.Println(s)
}

func test12(s []int) []int {
	//如果使用append操作切片可能改变切片的地址 需要使用返回值给实参赋值
	s = append(s, 4, 5, 6)
	fmt.Printf("%p\n", s)

	fmt.Println(s)
	return s
}

func main03903() {
	s := []int{1, 2, 3}
	fmt.Printf("%p\n", s)
	//s = test1(s)
	fmt.Println(s)
	fmt.Printf("%p\n", s)
}
