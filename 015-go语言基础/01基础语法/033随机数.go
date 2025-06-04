package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main03301() {
	//1、导入头文件 math/rand time
	//2、添加随机数种子
	//3、使用随机数
	start := time.Now().Nanosecond()
	//创建随机数种子
	rand.Seed(time.Now().UnixNano())
	for i := 0; i < 10000; i++ {
		//根据时间 1970.1.1.0.0.0
		fmt.Println(rand.Intn(100)) //0-99   %100
	}

	//fmt.Println(time.Now())
	//fmt.Println(time.Now().Second())
	end := time.Now().Nanosecond()

	fmt.Println(end - start)
}

/* BubbleSort
冒泡排序
*/
func BubbleSort(arr [10]int) [10]int {
	for i := 0; i < len(arr)-1; i++ {
		for j := 0; j < len(arr)-1-i; j++ {
			if arr[j] > arr[j+1] {
				arr[j], arr[j+1] = arr[j+1], arr[j]
			}
		}
	}

	return arr
}

func main03302() {
	var arr [10]int

	rand.Seed(time.Now().UnixNano())
	for i := 0; i < len(arr); i++ {
		arr[i] = rand.Intn(100) //0-99
	}

	arr = BubbleSort(arr)
	fmt.Println(arr)

}

//福利彩票  双色   红球有6个  1-33  不能重复  蓝球 1-16 随机一个
//rand.Intn(33)+1//1-33
