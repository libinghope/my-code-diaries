package main

import "fmt"

func main0201() {
	var slice []int =[]int{1,2,3,4,5}

	//p:=&slice//*[]int

	var p *[]int            //二级指针
	p=&slice

	//fmt.Printf("%T",p)

	//切片名本身就是一个地址
	//fmt.Printf("%p\n",slice)
	//fmt.Printf("%p\n",p)
	//fmt.Printf("%p\n",*p)

	//(*p)[1]=200//ok
	//p[1]=123 //err 不能通过指针访问切片中的元素
	fmt.Println(slice)
	fmt.Println(*p)


}


func main(){
	var slice []int =[]int{1,2,3,4,5}

	fmt.Printf("%p\n",slice)

	//p:=&slice//*[]int

	var p *[]int            //二级指针
	p=&slice

	*p=append(*p,6,7,8,9,10)

	fmt.Printf("%p\n",slice)
	fmt.Println(slice)
}