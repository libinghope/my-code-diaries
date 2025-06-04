package main

import "fmt"

func main0501() {
	//声明变量
	//var a int
	////& 运算符  取地址运算符
	//fmt.Scan(&a)
	//fmt.Println(a)
	//%p 占位符 表示输出一个数据对应的内存地址 &a
	//0x表示十六进制数据
	//fmt.Printf("%p",&a)

	//空格或者回车作为接收结束
	//var str string
	//fmt.Scan(&str)
	//fmt.Println(str)
	//接收两个数据
	var s1,s2 string
	fmt.Scan(&s1,&s2)
	fmt.Println(s1)
	fmt.Println(s2)
}
func main0502(){
	var r float64
	//PI:=3.14159
	var PI float64
	//通过键盘获取半径
	fmt.Scan(&r,&PI)
	fmt.Printf("面积：%.2f\n",PI*r*r)
	fmt.Printf("周长：%.2f\n",PI*2*r)
}
func main0503(){
	var a int
	var b string
	fmt.Scanf("%3d",&a)
	fmt.Scanf("%s",&b)
	fmt.Println(a)
	fmt.Println(b)
}

func main0504()  {
	//var name string
	//var passwd string
	//fmt.Println("请输入用户名")
	//fmt.Scanf("%s",&name)
	//fmt.Println("请输入密码")
	//fmt.Scanf("%s",&passwd)
	//fmt.Println(name,passwd)
	var Int int
	Int=10
	fmt.Println(Int)

}