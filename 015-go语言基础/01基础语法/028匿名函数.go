package main

import "fmt"

func main02801() {

	//a:=10
	//b:=20

	////匿名内部函数
	////f  是函数类型对应的变量
	//f:=func (a int , b int){
	//	fmt.Println(a+b)
	//}
	//
	//f(a,b)
	//f(20,30)

	//f:=func(){
	//	fmt.Println("hello world")
	//}
	//f()
	//f()
	//f()

}
func main02802() {
	a := 10
	b := 20
	//匿名函数  带返回值的匿名函数
	//v:=func(a int, b int)int{
	//	return a+b
	//}(a,b)
	f := func(a int, b int) int {
		return a + b
	}
	//函数调用 f 函数类型  v 接收返回值  类型为int
	v := f(a, b)
	fmt.Printf("%T", f)

	//func (){
	//
	//}()
	//{
	//
	//}

	fmt.Println(v)
	fmt.Printf("%T", v)
}
