package main

import "fmt"

type FuLei struct {
	num1 int
	num2 int
}
type JiaFaZiLei struct {
	FuLei
}
type JianFaZiLei struct {
	FuLei
}

type JieKou interface {
	JiSuan()int
}

func DuoTai(jiekou JieKou)(value int){
	value=jiekou.JiSuan()
	return
}
func (jiafa *JiaFaZiLei)JiSuan() int{
	return jiafa.num1+jiafa.num2
}

func (jianfa *JianFaZiLei)JiSuan()int{
	return jianfa.num1-jianfa.num2
}

type GongChang struct {

}
func (gongchang *GongChang)JiSuanJieGuo(num1 int,num2 int,yunsuanfu string)(value int){

	//创建接口变量
	var jiekou JieKou
	switch yunsuanfu {
	case "+":
		//创建对象
		var jiafa JiaFaZiLei=JiaFaZiLei{FuLei{num1,num2}}
		//value=jiafa.JiSuan()
		jiekou=&jiafa
	case "-":
		var jianfa JianFaZiLei=JianFaZiLei{FuLei{num1,num2}}
		//value=jianfa.JiSuan()
		jiekou=&jianfa
	}
	//value=jiekou.JiSuan()
	value=DuoTai(jiekou)
	return
}
func main(){
	var gongchang GongChang
	value:=gongchang.JiSuanJieGuo(10,20,"-")
	fmt.Println(value)
}