package main

import "fmt"

func main03002() {

	//var 变量名 数据类型

	//数组定义和使用
	//var 数组名 [元素个数]数据类型
	//var arr [10]int
	//
	////数组名[下标]=值
	//
	//arr[0]=123
	//arr[1]=10

	//数组下标是从0开始的  到数组下标的最大值为数组元素个数-1
	var arr [10]int = [10]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}

	//fmt.Println(arr[0])
	//fmt.Println(arr[1])
	//fmt.Println(arr[2])
	//fmt.Println(arr[3])
	////打印数组名可以显示所有元素
	//fmt.Println(arr)

	//打印数组信息
	//for i:=0;i<10;i++{
	//	fmt.Println(arr[i])
	//}

	//len(string) 获取字符串有效长度
	//len(...int) 获取不定参函数参数个数
	//len([10]int) 计算数组元素个数

	//fmt.Println(len(arr))
	//for i := 0; i < len(arr); i++ {
	//	fmt.Println(arr[i])
	//}

	//range 遍历集合信息
	//返回值为 下标  值
	for _, v := range arr {
		fmt.Println(v)
	}
}

func main0402() {
	//数组在定义时 可以初始化部分元素的值
	//var arr [10]int=[10]int{1,2,3,4,5}
	//使用自动类型推导创建数组
	//arr:=[10]int{1,2,3,4,5,6,7,8,9,10}

	//使用自动类型推导 可以根据元素个数创建数组
	arr := [...]int{1, 2, 3}

	for _, v := range arr {
		fmt.Println(v)
	}
	fmt.Printf("%T", arr)
}

func main03001() {
	//arr:=[5]int{1,2,3,4,5}
	//在定义时 叫元素个数
	var arr [5]int = [5]int{1, 2, 3, 4, 5}
	//在数组使用时叫下标 （0~len(arr)-1）
	//arr[5]=100//数组下标越界
	//arr[-1]=20//数组下标越界
	//数组在定义后 元素个数就已经固定 不能添加
	//fmt.Println(arr)
	//数组是一个常量 不允许赋值 数组名代表整个数组
	//arr=10//err
	//数组名也可以表示数组的首地址
	fmt.Printf("%p\n", &arr)
	fmt.Printf("%p\n", &arr[0])
	fmt.Printf("%p\n", &arr[1])
}
