package main

import "fmt"

func demo(i int){

	//recover()使用一定要在错误出现之前 进行拦截
	//通过匿名函数和recover()进行错误拦截
	defer func(){
		//recover可以从panic 异常中重新获取控制权
		//recover()//返回值为接口类型

		//fmt.Println(recover())
		err:=recover()
		if err!=nil{
			fmt.Println("demo函数异常：19-33行",err)
		}
	}()
	fmt.Println("1")
	//空指针引用
	var p *int
	*p=123//err  //recover作用范围

	fmt.Println("2")
	//数组元素个数为10个  len(arr)  数组下标是从0-9
	var arr [10]int


	//如果传递超出数组下标值 导致数组下标越界
	arr[i]=100//panic 系统处理  导致程序崩溃

	fmt.Println(arr)
}
func demo1(){
	fmt.Println("hello world")
}
func main() {
	demo(11)
	demo1()
}
