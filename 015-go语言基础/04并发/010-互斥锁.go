package main

import (
	"fmt"
	"time"
	"sync"
)

// 使用channel 完成同步
/*var ch = make(chan int)

func printer(str string)  {
	for _, ch := range str {
		fmt.Printf("%c", ch)
		time.Sleep(time.Millisecond * 300)
	}
}

func person1()  {				// 先
	printer("hello")
	ch <- 98
}

func person2()  {				// 后
	<- ch
	printer("world")
}

func main()  {
	go person1()
	go person2()
	for {
		;
	}
}
*/

// 使用 “锁” 完成同步 —— 互斥锁
var mutex sync.Mutex		// 创建一个互斥量， 新建的互斥锁状态为 0. 未加锁。 锁只有一把。

func printer(str string)  {
	mutex.Lock()			// 访问共享数据之前，加锁
	for _, ch := range str {
		fmt.Printf("%c", ch)
		time.Sleep(time.Millisecond * 300)
	}
	mutex.Unlock()			// 共享数据访问结束，解锁
}

func person1()  {				// 先
	printer("hello")
}

func person2()  {				// 后
	printer("world")
}

func main()  {
	go person1()
	go person2()
	for {
		;
	}
}




















