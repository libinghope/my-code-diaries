package main

import "fmt"

func main0601() {
	//bool类型
	var a bool
	fmt.Println(a)
	a = true
	fmt.Println(a)
	b := true
	fmt.Println(b)
}
func main0602() {
	var a float32
	var b float64
	//float32默认小数位置保留7位有效数据  会在末尾+1操作
	a = 3.141593400000000
	//float64默认小数位置保留15位有效数据
	b = 3.1415936273242342324367464375

	fmt.Println(a)
	fmt.Println(b)
}
func main0603() {
	var a byte = '0'
	var b byte = 'a'
	//打印字符型对应的ASCII值
	//'0' 48  'a' 97 'A' 65
	//fmt.Println(a)
	//fmt.Println(b)
	fmt.Printf("%c,%c", a, b)
}
func main0604() {
	//var a string//"\0"表示字符串的结束标志 "\n"表示换行“传智播客”
	//fmt.Println("==",a,"==")

	var a string = "首家天上人间上线了"
	var b string = "我来测试下怎么样"

	//字符串相加  将两个字符串连接起来
	//c:=a+b
	//fmt.Println(c)
	//==运算符  比较两个字符串内容是否相同
	fmt.Println(a == b)
}
