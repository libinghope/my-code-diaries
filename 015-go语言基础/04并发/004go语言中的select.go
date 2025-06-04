package main

import "fmt"

func main() {
	ch := make(chan int, 1)
	for {
		select {
		case ch <- 0:
		case ch <- 1:
		}
		i := <-ch
		fmt.Println("Value received:", i)
	}
}

/*
早在Unix时代，select机制就已经被引入。通过调用select()函数来监控一系列的文件描述符(句柄)
一旦其中一个文件句柄发生了IO动作，该select()调用就会被返回。后来该机制也被用于
实现高并发的Socket服务器程序。Go语言直接在语言级别支持select关键字，用于处理异步IO
问题。
select的使用很像switch
在上面的代码中，向ch中写入0或者1，但究竟会哪一个先执行，不确定
会形成类似随机数的功能
*/
