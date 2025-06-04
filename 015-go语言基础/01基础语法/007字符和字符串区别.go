package main

import "fmt"

func main0101() {

	//var a byte ='a'
	//var b string ="a"//'a''\0'
	//换行\n  \\表示一个\  一遍用于文件操作
	//var b string ="hello\nworld"
	var b string = "hello\077world"
	//%s 遇到\0停止
	//fmt.Printf("%s",b)
	fmt.Println(b)
	//fmt.Println(a==b)

}
func main0102() {
	//var str string="hello world"
	//在go语言中一个汉字算作3个字符 为了和linux同一处理
	var str string = "这是个字符串"
	//计算字符串个数
	num := len(str) //4  //8 //12
	fmt.Println(num)
}
