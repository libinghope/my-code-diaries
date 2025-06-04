package main

import "fmt"

func main() {


	var p *[]int
	fmt.Printf("%p\n",p)
	p=new([]int)
	fmt.Printf("%p\n",p)

	*p=append(*p,1,2,3)
	//for i := 0; i<len(*p);i++  {
	//	fmt.Println((*p)[i])
	//}
	for i,v:=range *p{
		fmt.Println(i,v)
	}
	//fmt.Println(len(*p))




}
