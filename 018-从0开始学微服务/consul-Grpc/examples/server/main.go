package main

import (
	"LearnGrpc/discovery"
	"LearnGrpc/discovery/register"
	"LearnGrpc/examples/proto"
	"context"
	"fmt"
	"net"
	"time"

	"google.golang.org/grpc"
	"google.golang.org/grpc/reflection"
)

type server struct {
}

var count int = 0

//服务端实现的方法，给远程客户端调用
func (s *server) SayHello(ctx context.Context, in *proto.HelloRequest) (*proto.HelloResponse, error) {
	count++
	fmt.Println("client called! num: ", count)
	return &proto.HelloResponse{Result: "hi," + in.Name + "!"}, nil
}

const (
	host       = "127.0.0.1"
	port       = 8081
	consulPort = 8500
)

//以下都是固定套路
func main() {
	listen, err := net.ListenTCP("tcp", &net.TCPAddr{net.ParseIP(host), port, ""})
	if err != nil {
		fmt.Println(err.Error())
	}
	s := grpc.NewServer()

	//向consul注册服务,注册之后客户端才能向consul查询
	cr := register.NewConsulRegister(fmt.Sprintf("%s:%d", host, consulPort), 15)
	cr.Register(discovery.RegisterInfo{
		Host:           host,
		Port:           port,
		ServiceName:    "HelloService",
		UpdateInterval: time.Second})

	proto.RegisterHelloServiceServer(s, &server{})
	reflection.Register(s)
	if err := s.Serve(listen); err != nil {
		fmt.Println("failed to serve:" + err.Error())
	}
}
