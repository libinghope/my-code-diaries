package main

import "fmt"

//接口
type Humaner1 interface { //子集
	SayHi()
}
//接口
type Personer1 interface { //超集
	Humaner1 //一组子集的集合
	Sing(string)
}

type student3 struct {
	name string
	age int
	sex string
}

func (s *student3)SayHi(){
	fmt.Printf("大家好，我是%s，我今年%d岁了，我是%s生\n",s.name,s.age,s.sex)
}

func (s *student3)Sing(name string){
	fmt.Printf("大家好，我叫%s,我给大家唱一首：%s\n",s.name,name)
}

func main() {

	var h Humaner1//子集
	h=&student3{"韩红",40,"女"}
	h.SayHi()


	var p Personer1//超集
	p=&student3{"王菲",18,"女"}
	p.SayHi()
	p.Sing("传奇")

	//将超级转成子集  翻过来不允许
	h=p//ok
	//p=h//err

	p.SayHi()

}
