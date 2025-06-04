package main

import "fmt"

func main04101() {

	//m:=make(map[byte]int)
	m := make(map[int]string, 1)
	//在map中值允许重复
	m[0] = "刘备"
	m[1] = "张飞"
	m[2] = "张飞"

	//fmt.Println(m[2])
	//在map打印中如果出现没有定义的map 默认值为空
	//fmt.Println("---",m[3],"---")

	//v,ok:=m[3]
	//if ok {
	//	fmt.Println(v)
	//}else {
	//	fmt.Println("可以不存在")
	//}

	for k, v := range m {
		//v,ok:=m[k]
		fmt.Println(k, v)
	}
}
