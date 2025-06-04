package main

import "fmt"

type stu struct {
	name string
	age int
	score int
}
func main0501() {

	//定义map
	m:=make(map[int]stu)

	m[101]=stu{"周瑜",28,101}
	m[102]=stu{"孙策",32,78}

	//fmt.Println(m)
	for k,v:=range m{
		fmt.Println(k,v)
	}

}
func main(){
	m:=make(map[int][]stu)
	m[101]=append(m[101],stu{"曹操",50,88},stu{"张辽",38,98},stu{})
	m[102]=append(m[102],stu{"刘备",50,88},stu{"张飞",38,98})
	m[103]=append(m[103],stu{"孙权",50,88},stu{"甘宁",38,98},stu{"太史慈",38,98})

	//m[101][1].name="张文远"
	for k,v:=range m {
		for i,data:=range v{

			if data.name=="张飞"{
				fmt.Println(k,i,data)
			}
			//fmt.Println("key:",k,"index",i,"value:",data)
		}
	}

}