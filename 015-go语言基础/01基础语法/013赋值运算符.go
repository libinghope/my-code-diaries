package main

import "fmt"

func main0701() {
	a:=10
	//a=a+5
	//a += 5
	//a-=5
	//a*=5
	//a/=5
	//a%=5 a=a%5

	//a += 5*3//a=a+5*3
	//a+=5*a  //a=a+5*a a++
	b:=a+5*a
	fmt.Println(a)
	fmt.Println(b)

}
