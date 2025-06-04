package main

import "fmt"

//不定参函数 函数参数类型为 ...数据类型
func test(args ...int) {

	//fmt.Println(args)
	//len() 计算字符串有效长度
	//len() 计算不定参函数的长度
	for i := 0; i < len(args); i++ {
		fmt.Println("下标 ", i, "值 ", args[i])
	}

	//fmt.Println(len(args))
}

func plus(arr ...int) {
	sum := 0
	//for i:=0; i<len(arr);i++  {
	//	sum+=arr[i]
	//}
	//for 和range 可以遍历 集合中的数据信息  数组  切片 结构体数组  map
	for _, data := range arr {
		sum += data
	}
	fmt.Println(sum)
}

func main02302() {

	//test(1,2)
	//test(1,2,3,4)
	plus(1, 2)
	plus(1, 2, 3, 4)
	plus(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
}
