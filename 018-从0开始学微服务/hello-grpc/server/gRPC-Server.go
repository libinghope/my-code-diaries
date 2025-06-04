package main

import (
	"context"
	"fmt"
	pt "hello-grpc/mygrpc"
	"net"

	"google.golang.org/grpc"
)

const (
	post = "127.0.0.1:8000"
)

type server struct{}

//实现SayHello接口
func (s *server) SayHello(ctx context.Context, in *pt.HelloRequest) (*pt.HelloReply, error) {
	return &pt.HelloReply{Message: "hello" + in.Name}, nil
}

func main() {
	ln, err := net.Listen("tcp", post)
	if err != nil {
		fmt.Println("网络异常", err)
	}

	//创建一个grpc句柄

	srv := grpc.NewServer()

	pt.RegisterHelloWorldServiceServer(srv, &server{})

	err = srv.Serve(ln)
	if err != nil {
		fmt.Println("网络启动异常", err)
	}
}
