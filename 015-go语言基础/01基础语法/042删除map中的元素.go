package main

import "fmt"

func main04201() {
	m := map[int]string{101: "刘备", 105: "关羽", 106: "李逵"}

	//fmt.Printf("%T",m)
	//delete(map,key)
	delete(m, 101)
	//delete在删除map中的元素的时候 如果可以 不存在 不会报错
	//delete(m,104)
	//delete(m,107)

	fmt.Println(m)
}
