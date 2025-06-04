package main

import (
	"os"
	"fmt"
	"io"
)

func main() {
	//var fp *File
	//os.Create 创建文件时 文件不存在会创建一个新文件  如果文件存在会覆盖源内容
	fp,err:=os.Create("D:/a.txt")
	if err!=nil{
		fmt.Println("文件创建失败")
		return
	}
	defer fp.Close()

	//写入文件
	//\n在文件中是换行  window文本文件换行是\r\n
	//n,_:=fp.WriteString("itcast\r\n")

	//fmt.Println(n)
	//在go语言中 一个汉字是3个字符
	n,_:=fp.WriteString("美女\r\n")
	fmt.Println(n)
	fp.WriteString("来玩啊")
}
func main0602(){
	//创建文件
	fp,err:=os.Create("D:/a.txt")
	if err!=nil{
		fmt.Println("文件创建失败")
		return
	}
	//关闭文件
	defer fp.Close()
	//1、将字符切片写入文件中
	//b:=[]byte{'h','e','l','l','o'}
	//
	////文件对象.write(字符切片)
	//n,_:=fp.Write(b)
	//fmt.Println(n)

	//2、将字符串转成字符切片写入文件中
	//str:="helloworld"
	str:="锄禾日当午"
	//字符串和字符切片允许转换
	b:=[]byte(str)

	fp.Write(b)
}

func main0603(){
	//fp,err:=os.Create("D:/a.txt")

	//打开文件
	//os.Open(文件名)只读方式打开文件
	//os.Open("D:/a.txt")
	//openfile不能创建新文件
	//os.openfile(文件名，打开模式，打开权限)

	fp,err:=os.OpenFile("D:/a.txt",os.O_RDWR,6)

	if err !=nil{
		fmt.Println("文件创建失败")
		return
	}

	defer fp.Close()
	//通过字符串获取字符切片
	//b:=[]byte("你瞅啥")
	////当使用writeat 进行指定位置插入数据时会依次覆盖源内容
	//fp.WriteAt(b,0)

	//获取文件字符个数
	//n,_:=fp.Seek(0,io.SeekEnd)
	//n,_:=fp.Seek(3,io.SeekStart)
	//负数是向左偏移 正数是想右偏移
	n,_:=fp.Seek(-3,io.SeekEnd)
	//b:=[]byte("abcd")
	//fp.WriteAt(b,n)
	fmt.Println(n)
}