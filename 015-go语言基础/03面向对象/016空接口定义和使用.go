package main

import "fmt"

func main0601() {
	//fmt.Println("hello")
	//fmt.Println(10)
	//fmt.Println(3.14)
	//fmt.Println(test)

	//空接口  可以接收任意类型数据
	var i interface{}
	i=10
	fmt.Println(i)
	fmt.Printf("%p\n",&i)
	i="hello world"
	fmt.Println(i)
	fmt.Printf("%p\n",&i)


	var arr [3]int=[3]int{1,2,3}
	i=arr
	fmt.Println(i)
	fmt.Printf("%p\n",&i)

}


func main(){
	//空接口切片
	var i []interface{}
	//i:=make([]interface{},3)
	i=append(i,1,2,"hello","你瞅啥",[3]int{1,2,3})

	//for j:=0;j<len(i);j++{
	//	fmt.Println(i[j])
	//}

	for idx,v:=range i{
		fmt.Println(idx,v)
	}

}