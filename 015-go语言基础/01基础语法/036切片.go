package main

import "fmt"

func main03601() {
	//数组定义 var  数组名 [元素个数]数据类型

	//切片定义 var 切片名 []数据类型

	//var s [] int
	//fmt.Println(s)
	//自动推导类型创建切片  make([]数据类型,5)
	s := make([]int, 5)
	//通过下标为切片赋值
	s[0] = 123
	s[1] = 234
	s[2] = 345
	s[3] = 456
	s[4] = 567
	//s[6]=678//err
	//通过append 添加切片信息
	s = append(s, 678, 789, 8910)

	fmt.Println(s)

	//通过len查看切片长度

	fmt.Println(len(s))
}
func main03602() {
	s := make([]int, 5)

	s[0] = 123
	s[1] = 234
	s[2] = 345
	s[3] = 456
	s[4] = 567

	//遍历

	//for i := 0; i<len(s);i++  {
	//	fmt.Println(s[i])
	//}

	for i, v := range s {
		fmt.Println(i, v)
	}
	fmt.Println(s)
}

func main03603() {
	//不写元素个数叫切片 必须写元素个数的叫数组
	var s []int = []int{1, 2, 3, 4, 5}

	s = append(s, 6, 7, 8, 9)

	//容量大于等于长度
	//fmt.Println(s)
	fmt.Println("长度：", len(s))
	fmt.Println("容量：", cap(s))

	//容量每次扩展为上次的倍数
	s = append(s, 6, 7, 8, 9)

	//fmt.Println(s)
	fmt.Println("长度：", len(s))
	fmt.Println("容量：", cap(s))

	s = append(s, 6, 7, 8, 9)

	fmt.Println("长度：", len(s))
	fmt.Println("容量：", cap(s))

	//如果整体数据没有超过1024字节 每次扩展为上一次的倍数  超过1024 每次扩展上一次的1/4
	s = append(s, 6, 7, 8, 9)

	fmt.Println("长度：", len(s))
	fmt.Println("容量：", cap(s))
}

func main03604() {
	s := make([]int, 5)
	s[0] = 1
	//使用append在长度后添加数据
	s = append(s, 1, 2, 3)
	//
	//fmt.Println(s)
	//fmt.Println(cap(s))
	//在切片打印时 只能打印有效长度中的数据 cap不能作为数组打印的条件
	for i := 0; i < len(s); i++ {
		fmt.Println(s[i])
	}
}
