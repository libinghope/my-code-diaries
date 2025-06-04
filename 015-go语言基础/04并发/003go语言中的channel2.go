package main

import "fmt"

func main() {
	ch := make(chan string) // 无缓冲channel
	// len(ch) ： channel 中剩余未读取数据个数。 cap（ch）： 通道的容量。
	fmt.Println("len(ch)=", len(ch), "cap(ch)=", cap(ch))
	go func() {
		for i := 0; i < 2; i++ {
			fmt.Println("i = ", i, "len(ch)=", len(ch), "cap(ch)=", cap(ch))
		}
		// 通知主go打印完毕
		ch <- "子go打印完毕"
	}()

	str := <-ch
	fmt.Println("str=", str)
}
