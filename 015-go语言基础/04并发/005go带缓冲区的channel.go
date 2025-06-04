package main

import (
	"fmt"
)

func main() {
	ch := make(chan int, 5) // 存满5个元素之前，不会阻塞
	fmt.Println("len=", len(ch), "cap=", cap(ch))

	go func() {
		for i := 1; i <= 10; i++ {
			ch <- i
			len := len(ch)
			cap := cap(ch)
			fmt.Println("子go程：i = ", i, "len=", len, "cap=", cap)
		}
	}()
	//time.Sleep(time.Second * 3)
	for j := 1; j <= 8; j++ {
		num := <-ch
		fmt.Println("主go程：j = ", j, "读取到 num = ", num)
	}
}

/*
子go程，向缓冲区写入数据，当写入到第6个的时候，缓冲区满，子go程阻塞，可能“放入6” “放入7”的操作都在等待

主go程执行，取出1-5，此时缓冲区为空，再读取就直接拿等待队列中的数据，就没有存入取出的动作了

*/
