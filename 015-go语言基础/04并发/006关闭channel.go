package main

import (
	"fmt"
	"time"
)

/*func main()  {
	ch := make(chan int)

	go func() {
		for i:=0; i<8;i++ {
			ch <- i
		}
		close(ch)		// 写端，写完数据主动关闭channel
		//ch <- 790
	}()

	for {
		if num, ok := <- ch; ok == true {
			fmt.Println("读到数据：", num)
		} else {
			n := <- ch
			fmt.Println("关闭后：", n)
			break
		}
	}
}*/

func main() {
	ch := make(chan int, 0)

	go func() {
		for i := 0; i < 5; i++ {
			ch <- i
		}
		close(ch) // 写端，写完数据主动关闭channel
		//ch <- 790
		x, ok := <-ch //ok是false就说明chan已经关闭
		fmt.Println("子go 结束")
	}()
	time.Sleep(time.Second * 2)
	/*	for {
		if num, ok := <- ch; ok == true {
			fmt.Println("读到数据：", num)
		} else {
			n := <- ch
			fmt.Println("关闭后：", n)
			break
		}
	}*/
	for num := range ch {
		fmt.Println("读到数据：", num)
	}
}
