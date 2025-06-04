package main

import "fmt"

//Count 计数
func Count(ch chan int, i int) {
	fmt.Println("Counting :", i)
	ch <- 1 //向ch中写入数据，相当于是生产者，如果为空就阻塞等待
}
func main() {
	chs := make([]chan int, 10)
	for i := 0; i < 10; i++ {
		chs[i] = make(chan int)
		go Count(chs[i], i)
	}
	for _, ch := range chs {
		<-ch //取出ch中的数据,相当于是消费者，如果为空就阻塞等待
	}

	ch := make(chan int)

	go func() {
		for i := 0; i < 5; i++ {
			fmt.Println("子go程， i=", i)
			ch <- i // ch <- 0
		}
	}()
	//time.Sleep(time.Second * 2)
	for i := 0; i < 5; i++ {
		num := <-ch
		fmt.Println("主go程读：", num)
	}
}

/*
channel是Go语言在语言级别提供的goroutine间的通信方式。我们可以使用channel在两个或
多个goroutine之间传递消息。channel是进程内的通信方式，因此通过channel传递对象的过程和调
用函数时的参数传递行为比较一致，比如也可以传递指针等。可以把channel看做是一种类型安全的管道.

在上面的代码中，定义了一个包含10个channel的数组（名为chs），并把数组中的每个
channel分配给10个不同的goroutine。在每个goroutine的Counting()函数完成后，我们通过ch <- 1语
句向对应的channel中写入一个数据。在这个channel被读取前，这个操作是阻塞的。在所有的
goroutine启动完成后，我们通过<-ch语句从10个channel中依次读取数据。在对应的channel写入
数据前，这个操作也是阻塞的。这样，我们就用channel实现了类似锁的功能，进而保证了所有
goroutine完成后主函数才返回。比共享内存的方式简单、优雅的多。
我们在使用Go语言开发时，经常会遇到需要实现条件等待的场景，这也是channel可以发挥
作用的地方。
*/
