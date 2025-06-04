package main

import "fmt"

//方法也是全局的  允许程序在所有文件访问 对象.方法

//方法1 打招呼

func (s *student2) SayHello() {
	fmt.Printf("大家好，我叫%s，我今年%d岁了，我是%s生\n", s.name, s.age, s.sex)
}

//方法名可以和函数名重名
func SayHello(){
	fmt.Println("hello world")
}

//方法2 打印成绩
func (s *student2) PrintScore() {
	sum := s.cscore + s.escore + s.mscore

	fmt.Printf("总成绩为：%d  平均成绩：%d\n", sum, sum/3)
}