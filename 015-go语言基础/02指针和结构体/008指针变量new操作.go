package main

import "fmt"

func main() {
	var p *int//nil
	fmt.Println(p)
	//为指针变量创建一块内存空间
	//在堆区创建空间
	p=new(int)//new 创建好的空间值为数据类型的默认值

	//打印p的值
	fmt.Println(p)
	//打印p指向空间的值
	fmt.Println(*p)

}
