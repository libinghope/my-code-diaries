package main

import "fmt"

func main0101() {

	var arr [5]int = [5]int{123,2,3,4,5}


	//fmt.Printf("%p\n",&arr)
	//fmt.Printf("%p\n",&arr[0])

	//p:=&arr
	//定义指针指向数组
	var p *[5]int
	//将指针变量和数组建立关系
	p=&arr

	//可以通过指针间接操作数组
	//*p [0] ==  arr[0]
	//fmt.Println(*p)
	//fmt.Println(arr)
	//fmt.Println((*p)[0])
	//直接使用指针[下标]操作数组元素
	fmt.Println(p[0])
	//fmt.Printf("%p\n",p)
	//fmt.Printf("%T\n",p)


}
func main(){
	var arr [5]int = [5]int{123,2,3,4,5}
	//指向数组的指针
	//p:=&arr //*[5]int
	p:=&arr[0]
	fmt.Printf("%T",p)
	//len(指针变量)元素个数
	//fmt.Println(len(p))
	//for i := 0; i<len(p);i++  {
	//	fmt.Println(p[i])
	//}

	//fmt.Printf("%p\n",p)
	//fmt.Printf("%p\n",&arr) //*[5]int
	//fmt.Printf("%p\n",&arr[0]) //*int


}