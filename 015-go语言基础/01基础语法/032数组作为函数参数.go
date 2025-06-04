package main

import "fmt"

func test123(arr [10]int) {
	//
	//for i := 0; i < len(arr); i++ {
	//	fmt.Println(arr[i])
	//}
	arr[2] = 123

	fmt.Printf("%p\n", &arr)

}
func main0801() {
	//指定数组下标进行初始化操作
	//var arr [10]int=[10]int{1,2,3,4,5,7:10}

	arr := [10]int{9, 1, 5, 6, 7, 3, 10, 2, 4, 8}
	//数组作为函数参数是传递数组名
	//数组作为函数参数是值传递的
	//test(arr)
	//fmt.Println(arr)
	fmt.Printf("%p\n", &arr)
	//fmt.Println(arr)
}

//func BubbleSort(arr [10]int) [10]int{
//	for i := 0; i < len(arr)-1; i++ {
//		for j := 0; j < len(arr)-1-i; j++ {
//			if(arr[j]>arr[j+1]){
//				arr[j],arr[j+1]=arr[j+1],arr[j]
//			}
//		}
//	}
//
//	return arr
//}

func main03201() {
	arr := [10]int{9, 1, 5, 6, 7, 3, 10, 2, 4, 8}
	fmt.Printf("%T", arr) //[10]int
	//只读变量
	//arr = [10]int{1,2,3}
	//arr=BubbleSort(arr)

	fmt.Println(arr)

}
