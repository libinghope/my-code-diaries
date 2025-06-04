package main

import "fmt"

func main03501() {

	//一维数组
	//var 数组名 [元素个数] 数据类型
	//二维数组
	//var 数组名 [行个数][列个数] 数据类型

	//var arr [3][4]int
	//
	////通过行和列下标找到具体元素
	//arr[1][2]=3
	//arr[2][1]=4

	var arr [3][4]int = [3][4]int{{1, 2}, {2, 3, 4}, {4, 3: 10}}

	//fmt.Println(arr)

	for i := 0; i < 3; i++ {
		for j := 0; j < 4; j++ {
			fmt.Print(arr[i][j], " ")
		}
		fmt.Println()
	}
}

func main03502() {
	var arr [3][4]int
	//len(二维数组名) 二维数组的行数
	fmt.Println(len(arr))
	//arr[0]表示二维数组的第一行
	//len(二维数组名[下标])  二维数组列数
	fmt.Println(len(arr[0]))

	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr[0]); j++ {
			fmt.Print(arr[i][j], " ")
		}
		fmt.Println()

	}

}
