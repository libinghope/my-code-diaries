package main

import "fmt"

func main1101(){
	var score int
	fmt.Scan(&score)

	//if 条件判断根据是否满足条件指向对应的代码
	//else 作为if 补充条件 如果条件不满足执行else代码
	//格式 if 表达式{
	// 代码体
	// }else {
	// 代码体
	//}

	if score >700 {
		fmt.Println("我要上清华")
	} else{
		fmt.Println("我要上蓝翔")
	}

}
func main1102(){
	var score int
	fmt.Println("请输入分数")
	fmt.Scan(&score)
	//if else if
	//else 配对和if 一起使用  选择同级别下的if进行配对使用
	if score>700{
		fmt.Println("我要上清华")
		if score >720{
			fmt.Println("我要学习挖掘机")
		}else if score >710{
			fmt.Println("我要学习美容美发")
		}else {
			fmt.Println("我要学习计算机")
		}

	} else if score >680{
		fmt.Println("我要上北大")
		if score > 690{
			fmt.Println("我要学习盗墓")
		}else if score >685{
			fmt.Println("我要学习占卜")
		}else{
			fmt.Println("我要学习计算机")
		}

	} else if score >650{
		fmt.Println("我要上传智")
	}else{
		fmt.Println("我要上蓝翔")
	}
}
func main1103(){
	a:=10
	if a>5{
		fmt.Println(a)
	}
	//采用就近原则 找到上面尚未配对的if进行匹配操作
	if a>8{
		fmt.Println(a)
	}else {
		fmt.Println("haha")
	}
}

func main1104(){
	//三只小猪称体重
	//a=10 b=8 c=12

	var a,b,c int
	fmt.Println("请输入三只小猪体重")
	fmt.Scan(&a,&b,&c)

	if a > b {
		if a>c{
			fmt.Println("a重")
		}else{
			fmt.Println("c重")
		}
	}else {
		if b>c{
			fmt.Println("b重")
		}else{
			fmt.Println("c重")
		}
	}
}