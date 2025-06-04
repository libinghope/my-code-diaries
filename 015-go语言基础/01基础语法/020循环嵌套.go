package main

import "fmt"

func main02001() {

	//嵌套循环中  执行次数为外层*内层
	for i := 0; i < 5; i++ {

		for j := 0; j < 5; j++ {
			fmt.Println(i, j)
		}

	}
}
func main02002() {
	//九九乘法口诀
	/*
		1*1=1
		1*2=2 2*2=4
		1*3=3 2*3=6 3*3=9
		1*4=4 2*4=8 3*4=12 4*4=16
	*/
	//外层控制行  内层控制列
	for i := 1; i <= 9; i++ {
		for j := 1; j <= i; j++ {
			fmt.Print("*")
			//fmt.Printf("%d*%d=%d ",j,i,i*j)
			//if j==i{
			//	//在嵌套循环中 break 会跳出本次循环
			//	break
			//}
		}
		fmt.Println()
	}

}

//     *
//	  ***
//   *****
//  *******
// *********
//***********
