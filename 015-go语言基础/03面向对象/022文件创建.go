package main

import (
	"os"
	"fmt"
)

func main() {

	//路径分为 绝对路径 （从盘符开始到文件的位置）（linux中是以根目录开始的/） 相对路径 （相对某一个文件的位置）
	//\\是一个转义字符表示【\】 在一般文件操作中都是以【/】
	fp,err:=os.Create("D:/a.txt")
	//文件创建失败
	if err != nil{
		fmt.Println("文件创建失败")
		return//如果return出现在主函数中 表示程序的结束
	}

	//延迟调用 关闭文件
	//1、占用内存和缓冲区
	//2、文件打开上限  65535
	defer fp.Close()

	fmt.Println("文件创建成功")



}
