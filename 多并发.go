/*
建立socket，申明自身的port和IP，并绑定到socket，使用listen监听，然后不断用accept去
查看是否有连接。如果有，捕获socket，并通过recv获取消息的内容，通信完成后调用closeSocket
关闭这个对应accept到的socket。如果不需要等待任何客户端连接，那么用closeSocket直接关
闭自身的socket。
*/
package main

import (
	"fmt"
	"net"
	"strings"
)


func HandleConn(conn net.Conn){
	//调用完毕，自动关闭conn
	defer conn.Close()

	//获取客户端的网络地址信息
	addr:=conn.RemoteAddr().String()
	fmt.Printf("[%s] connect successful\n",addr)

	buf:=make([]byte,2048)  //切片存储数据

    for{
		//读取用户数据
		n,err:=conn.Read(buf)   //返回长度
		if err!=nil{
			fmt.Println("err=",err)
			return
		}
		fmt.Printf("[%s]: %s\n",addr,string(buf[:n]))

		//fmt.Println("len=",len(string(buf[:n])))
		if "exit"==string(buf[:n-1]){ //客户端退出输入exit,键盘输入多了1个字符，‘\n’
			fmt.Println(addr,"exit")
			return
		}

		//把数据转换为大写，再给用户发送
		conn.Write([]byte(strings.ToUpper(string(buf[:n]))))  //[]byte隐式赋值
	}

}
func main(){
	//监听，可以申明自身端口和IP，或者任意IP地址和端口
	listener,err:=net.Listen("tcp","127.0.0.1:8000")
	if err!=nil{
		fmt.Println("err=",err)
		return    //不执行下面的
	}
	defer listener.Close()  //主线程退出前关闭

	//接受多个用户
	for{
		conn,err1:=listener.Accept()
		if err1!=nil{
			fmt.Println("err1=",err1)
			return
		}
		//处理用户请求，多用户，创建新的协程
		go HandleConn(conn)
	}
}
