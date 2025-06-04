package main

import (
	"context"
	"fmt"
	pt "hello-grpc/mygrpc"

	"google.golang.org/grpc"
)

const (
	post = "127.0.0.1:8000"
)

func main() {
	conn, err := grpc.Dial(post, grpc.WithInsecure())

	if err != nil {
		fmt.Println("连接服务器失败", err)
	}

	defer conn.Close()

	c := pt.NewHelloWorldServiceClient(conn)

	//远程调用
	r1, err := c.SayHello(context.Background(), &pt.HelloRequest{Name: "熊猫阿宝"})

	if err != nil {
		fmt.Println("can't get server", err)
	}
	fmt.Println(r1.Message)

}
