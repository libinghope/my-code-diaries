package main

import "fmt"

func main() {
	//指针切片
	var slice []*int
	a:=10
	b:=20
	c:=30
	d:=40
	slice=append(slice,&a,&b,&c)

	slice=append(slice,&d)
	fmt.Println(slice)


	for i,v:=range slice{
		//fmt.Printf("%T",v)
		fmt.Println(i,*v)
	}

}
