package main

import "fmt"

//if 可以嵌套 可以判断区间  执行效率比较低
//switch 执行效率高  不能嵌套和区间判断
func main01801() {

	var w int
	fmt.Scan(&w)
	//!swich中的case不能是浮点型数据 浮点型数据是一个约等于的数据
	//switch case可以是一个整型变量
	switch w {
	case 1:
		fmt.Println("星期一")
	case 2:
		fmt.Println("星期二")
	case 3:
		fmt.Println("星期三")
	case 4:
		fmt.Println("星期四")
	case 5:
		fmt.Println("星期五")
	case 6:
		fmt.Println("星期六")
	case 7:
		fmt.Println("星期日")
	//如果输入的值没有找到 默认进入default 中
	default:
		fmt.Println("输入错误")
	}

	//switch score>700 {
	//case true:
	//	fmt.Println(score)
	//case false:
	//	fmt.Println(score)
	//}
}
func main01802() {
	var score int
	fmt.Println("请输入分数")
	fmt.Scan(&score)

	switch score / 10 {
	case 10:
		//fmt.Println("A")
		fallthrough //让switch执行下一个分支的代码  如果不写 执行到下一个分支就会自动停止
	case 9:
		fmt.Println("A")
	case 8:
		fmt.Println("B")
	case 7:
		fmt.Println("C")
	case 6:
		fmt.Println("D")
	default:
		fmt.Println("E")
	}
}
