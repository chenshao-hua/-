package main

import (
	"fmt"
	"net"
)
import "os"
import "io"

//发送文件内容
func SendFile(path string,conn net.Conn){
	//以只读方式打开文件
	rf,err:=os.Open(path)
	if err!=nil{
		fmt.Println("os.Open err=",err)
		return
	}

	//退出前，关闭文件
	defer rf.Close()

	//读文件内容，读多少发多少
	buf:=make([]byte,1024*4)

	for{
		n,err1:=rf.Read(buf)  //从文件读取内容
		if err1!=nil{
			if err1==io.EOF{
				fmt.Println("文件发送完毕！")  //io.EOF表示读取到末尾结束，是输入流的结尾
			}else{
				fmt.Println("rf.Read err1=",err1)
			}
			return
		}
        //发送内容
        conn.Write(buf[:n])  //给服务器
	}
}


func main(){
	//提示输入文件
	fmt.Println("请输入需要传输的文件：")
	var path string
	fmt.Scan(&path)

	//获取文件名 info.Name()
	info,err:=os.Stat(path)
	if err!=nil{
		fmt.Println("os.Stat err=",err)
		return
	}

	//主动连接服务器
	conn,err1:=net.Dial("tcp","127.0.0.1:8000")
	if err1!=nil{
		fmt.Println("net Dial err1=",err1)
	}

	//main退出后，关闭连接
	defer conn.Close()

	//给接收方，先发送文件名
	_,err2:=conn.Write([]byte(info.Name()))  //转换成字符串
	if err2!=nil{
		fmt.Println("conn.Write err2=",err2)
		return
	}

	//接受对方的回复，如果回复“ok”，则说明对方已经准备好，可以发送文件
	buf:=make([]byte,1024) //缓冲数据
	n,err3:=conn.Read(buf)
	if err3!=nil{
		fmt.Println("conn.Read err3=",err3)
		return
	}

	if "ok"==string(buf[:n]){
		//发送文件内容
		SendFile(path,conn)
	}

}