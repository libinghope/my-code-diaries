package main

import "fmt"

func main() {

	//var arr []interface{}
	arr:=make([]interface{},5)
	arr[0]=123
	arr[1]=3.1456
	arr[2]="hello"
	arr[3]=1.234
	arr[4]=[]int{1,2,3}

	for _,v:=range arr{
		//对数据v进行类型断言
		//data,ok:=v.(int)
		//if ok{
		//	fmt.Println(data)
		//}
		if data,ok:=v.(int); ok{
			fmt.Println("整型数据：",data)
		}else if data,ok:=v.(float64);ok{
			fmt.Println("浮点型数据：",data)
		}else if data,ok:=v.(string);ok{
			fmt.Println("字符串数据：",data)
		}else if data,ok:=v.([]int);ok{
			fmt.Println("切片数据：",data)
		}
	}

}
