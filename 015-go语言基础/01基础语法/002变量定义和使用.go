package main

import "fmt"

func main0201()  {

    //变量的定义和使用
    //声明 和 定义
    //var 变量名 数据类型
    //布尔类型 整型 浮点型 字符型 字符串类型
    //变量在定义时存储不同的数据  需要不同的数据类型
    var a int//声明  如果没有初始值  默认值为0
    a=10//赋值
    a=a+25
    //var a int = 10//定义

    fmt.Println(a)

}

func main0202(){
    //计算圆的面积和周长
    //面积 PI * r * r
    //周长 2 * PI * r
    //var PI float64=3.14159
    PI:=3.14159
    //var r float64=2.5
    r:=2.5
    wty:="你瞅啥"
    //var s float64
    //var l float64
    ////计算面积
    //s=PI*r*r
    ////计算周长
    //l=PI*2*r
    s:= PI * r * r
    l:= PI * 2 * r
    fmt.Println("面积：",s)
    fmt.Println("周长：",l)
    fmt.Println(wty)

}
func main0203(){
    //自动推到类型 变量名:=值 会根据值为变量选择类型
    //去市场买2斤黄瓜 价格为5 元
    w:=2.0//float64
    //p:=5//int
    p:=5.0
    //var p float64 = 5
    //在go语言中不同的数据类型不能进行计算 可以通过类型转换解决
    fmt.Println(w*p)
}

func main0204()  {
    a:=false//bool 布尔类型
    b:=10//int 整型
    c:=3.14//float64 浮点型
    d:='a'//byte 字节类型
    e:="瞅你咋地"//string 字符串类型

    fmt.Println(a,b,c,d,e)
}
