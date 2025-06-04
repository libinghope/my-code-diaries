package main

import "fmt"

func main() {
	for i := 0; i < 10; i++ {
		go add(i, i) //主进程不会等待协程执行完毕
	}
}

func add(x int, y int) {
	s := x + y
	fmt.Println(s)
}

/* 最终的结果似乎是什么都没有打印
“什么？！屏幕上什么都没有，程序没有正常工作！”
是什么原因呢？明明调用了10次Add()，应该有10次屏幕输出才对。要解释这个现象，就涉
及Go语言的程序执行机制了。
Go程序从初始化main package并执行main()函数开始，当main()函数返回时，程序退出，
且程序并不等待其他goroutine（非主goroutine）结束。
对于上面的例子，主函数启动了10个goroutine，然后返回，这时程序就退出了，而被启动的
执行Add(i, i)的goroutine没有来得及执行，所以程序没有任何输出。
加大循环的次数有可能看到部分输出。
*/
