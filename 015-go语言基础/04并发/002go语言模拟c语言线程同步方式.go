package main

import (
	"fmt"
	"runtime"
	"sync"
)

var counter int = 0

//Count 记数
func Count(lock *sync.Mutex) {
	lock.Lock()
	counter++
	fmt.Println(z)
	lock.Unlock()
}
func main() {
	lock := &sync.Mutex{}
	for i := 0; i < 10; i++ {
		go Count(lock)
	}
	for {
		lock.Lock()
		c := counter
		lock.Unlock()
		runtime.Gosched()
		if c >= 10 {
			break
		}
	}
}

/*
实现一个如此简单的功能，却写出如此臃肿而且难以理解的代码。
想象一下，在一个大的系统中具有无数的锁、无数的共享变量、无数的业务逻辑与错误处理分
支，那将是一场噩梦。这噩梦就是众多C/C++开发者正在经历的，其实Java和C#开发者也好不到
哪里去。go的出现其中一个目的就是为了解决这个问题
*/
