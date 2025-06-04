package main

import (
	"LearnGrpc/discovery/resolver"
	"LearnGrpc/examples/proto"
	"context"
	"fmt"
	"log"
	"time"

	"google.golang.org/grpc"
	"google.golang.org/grpc/balancer/roundrobin"
)

func main() {

	//consul的默认端口是8500,启动后可在本地访问localhost:8500
	//HelloService就是proto文件中定义的服务
	schema, err := resolver.GenerateAndRegisterConsulResolver("127.0.0.1:8500", "HelloService")
	if err != nil {
		log.Fatal("init consul resovler err", err.Error())
	}

	//建立连接
	conn, err := grpc.Dial(fmt.Sprintf("%s:///HelloService", schema), grpc.WithInsecure(), grpc.WithBalancerName(roundrobin.Name))
	if err != nil {
		log.Fatalf("did not connect: %v", err)
	}
	defer conn.Close()

	//客户端，这是固定套路
	c := proto.NewHelloServiceClient(conn)

	name := "熊猫阿宝"

	for {
		ctx, cancel := context.WithTimeout(context.Background(), time.Second)
		defer cancel()

		//调用远端的方法
		r, err := c.SayHello(ctx, &proto.HelloRequest{Name: name})
		if err != nil {
			log.Println("could not greet: %v", err)

		} else {
			log.Printf("Hello: %s", r.Result)
		}
		time.Sleep(time.Second)
	}

}
