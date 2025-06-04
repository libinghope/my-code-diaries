package main

import "fmt"

func main05() {
	//break  在循环中跳出循环
	//在嵌套循环中 跳出本层循环

	for i:=0;i<=100;i++ {
		//奇数
		if i%2==1{
			//结束本次循环继续下次循环
			continue
		}
		fmt.Println(i)
	}
}
//goto