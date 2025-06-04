package main

import "fmt"

func main01201() {
	a := 10
	b := 3.99
	//将不同类型转成相同类型进行计算操作
	//类型转换格式 数据类型（变量） 数据类型（表达式）
	//c:=float64(a)*b
	//将浮点型转成整型数据 保留浮点型整数部分 舍弃小数部分
	//*!不会进行四舍五入 切记·只是丢掉小数部分
	c := a * int(b)
	fmt.Println(c)
}
func main01202() {
	//虽然int32和int64都是整型 单数不允许相互转换
	//只有类型匹配的数据才能进行计算
	//在go语言中习惯将低类型转成高类型  保证数据完整性
	var a int32 = 10
	var b int64 = 20
	c := int64(a) + b
	fmt.Println(c)
	fmt.Printf("%T", c)
}
func main01203() {
	//fmt.Printf("%d周%d天\n",46/7,46%7)
	//编程实现107653秒是几天几小时几分钟几秒?
	//miao:=107653
	//fenzhong:=miao/60
	//xiaoshi:=fenzhong/60
	//tian:=xiaoshi/24
	//time:=107653
	//fmt.Println("天：",time/60/60/24%365)
	//fmt.Println("时：",time/60/60%24)
	//fmt.Println("分：",time/60%60)
	//fmt.Println("秒：",time%60)

}
