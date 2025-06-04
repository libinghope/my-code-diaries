package main

import "fmt"

func demo(m map[int]string) {
	//map在函数中添加数据 可以的  影响主调函数中实参的在
	m[102] = "杨二郎"
	m[103] = "唐老二"
	fmt.Println(len(m))

	delete(m, 101)
	fmt.Println(len(m))
}
func main04301() {
	m := make(map[int]string, 1)
	m[101] = "孙悟空"
	fmt.Println(len(m))
	//fmt.Println(cap(m))//err
	//map作为函数参数是地址传递 （引用传递）
	demo(m)

	fmt.Println(m)
}

//m:=make(map[int][]int)
//m:=make(map[int][]struct)
