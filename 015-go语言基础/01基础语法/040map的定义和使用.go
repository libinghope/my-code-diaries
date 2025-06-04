package main

import "fmt"

func main04001() {
	//map[keyType]valueTye

	//var m map[int]string
	m := make(map[int]string, 1)
	//map[key] key 是一个基本数据类型
	//map的长度是自动扩容的
	//map中的数据是无序存储的
	m[100] = "张三"
	m[2] = "李四"
	m[5] = "王五"
	//for i,v  index  v  value
	for k, v := range m {
		fmt.Println(k, v)
	}
	//fmt.Println(m)
}
func main04002() {
	m := make(map[string]int, 1)

	//重新赋值
	m["尼古拉斯赵四"] = 10
	//可以通过验证key对应的value是否有值  根据条件作出相应操作
	_, ok := m["尼古拉斯赵四"]
	if ok {
		fmt.Println("该key以存在")
	} else {
		m["尼古拉斯赵四"] = 20
	}
	//map中key和value不能翻过来操作
	//m[10]="布莱恩特王老七"//err
	//map在定义时 key是唯一的  不允许重复
	//m:=map[string]int{"尼古拉斯赵四":10,"迈克尔刘能":20}

	fmt.Println(m)
}
