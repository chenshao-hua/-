/*
建立socket，通过端口号和地址确定目标服务器，使用Connect连接到服务器，
send发送消息，等待处理，通信完成后调用closeSocket关闭socket
*/
package main

import "fmt"
import (
	"net"
	"os"
)

func main(){
	//主动连接服务器
	conn,err:=net.Dial("tcp","127.0.0.1:8000")

	if err!=nil{
		fmt.Println("net.Dial err=",err)
		return
	}

	//main调用完毕后，关闭连接
	defer conn.Close()

	//创建协程，用户端输入数据
	go func(){
		//客户端输入内容，发给服务器
		//切片缓冲
		str:=make([]byte,1024)
		for{
			n1,err2:=os.Stdin.Read(str)  //从键盘读取内容，存在str
			if err2!=nil{
				fmt.Println("os.Stdin.Read err2=",err2)
				return
			}
			//内容传给服务器
			conn.Write(str[:n1])
		}

	}()

	//接受服务器回复的数据
	//切片缓冲
	buf:=make([]byte,1024)
	for{
		n,err1:=conn.Read(buf) //接受服务器的请求
		if err1!=nil{
			fmt.Println("conn.Read err1=",err1)
			return
		}
		fmt.Println(string(buf[:n]))  //打印收到的内容，转换为字符串
	}
}