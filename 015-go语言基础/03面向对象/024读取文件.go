package main

import (
	"os"
	"fmt"
	"bufio"
	"io"
)

func main0701() {
	//只读方式打开文件
	fp,err:=os.Open("D:/a.txt")
	/*
	1、文件不存在
	2、文件权限
	3、文件打开上限
	 */
	if err !=nil{
		fmt.Println("文件打开失败")
		return
	}
	defer fp.Close()
	b:=make([]byte,100)
//换行也会作为字符一部分进行读取
	fp.Read(b)

	//fmt.Println(b)
	//for i:=0;i<len(b);i++{
	//	if b[i]!=0{
	//		fmt.Printf("%c",b[i])
	//
	//	}
	//}
	fmt.Println(string(b))
}


func main0702(){
	fp,err:=os.Open("D:/a.txt")
	if err !=nil{
		fmt.Println("文件打开失败")
		return
	}
	defer fp.Close()

	//创建切片缓冲区
	r:=bufio.NewReader(fp)
	//读取一行内容
	b,_:=r.ReadBytes('\n')
	//打印切片中字符的ASCII值
	//fmt.Println(b)
	//将切片转成string打印  汉字
	fmt.Print(string(b))
	//如果在文件截取中  没有标志位（分隔符）到文件末尾自动停止  EOF -1 文件结束标志
	b,_=r.ReadBytes('\n')

	fmt.Println(string(b))
}


func main0704(){
	fp,err:=os.Open("D:/源文件.txt")
	if err!=nil{
		fmt.Println("文件打开失败")
		return
	}
	defer fp.Close()
	b:=make([]byte,20)


	for{
		//读取文件返回值为 个数和错误信息
		n,err:=fp.Read(b)
		//io.EOF 表示文件的结尾 值为-1
		//eof  end of file
		if err == io.EOF{
			break
		}
		//if err !=nil{
		//	//io.EOF 表示文件的结尾 值为-1
		//	//eof  end of file
		//	if err == io.EOF{
		//		break
		//	}
		//}
		fmt.Print(string(b[:n]))
	}
}


func main(){
	fp,err:=os.Open("D:/源文件.txt")
	if err!=nil{
		fmt.Println("文件打开失败")
		return
	}
	defer fp.Close()

	//行读取
	r:=bufio.NewReader(fp)


	for{
		b,err:=r.ReadBytes('\n')

		fmt.Print(string(b))
		if  err == io.EOF{
			break
		}
	}


}