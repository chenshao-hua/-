package main

import "fmt"
import "os"
import "io"
import "net"

//接受文件内容
func RecvFile(fileName string,conn net.Conn){
	//新建文件
	wf,err:=os.Create(fileName)
	if err!=nil{
		fmt.Println("os.Create err=",err)
		return
	}

	buf:=make([]byte,1024*4)

	//接受多少，写多少
	for{
		n,err1:=conn.Read(buf) //接受对方发送过来的文件内容
		if err1!=nil{
			if err1==io.EOF{
				fmt.Println("文件接受完毕！")
			}else{
				fmt.Println("conn.Read err1=",err1)
			}
			return
		}

		if n==0{
			fmt.Println("n=0，文件接受完毕！")
			break
		}
		wf.Write(buf[:n])  //往文件写入内容
	}
}
func main(){
	//监听
	listener,err:=net.Listen("tcp","127.0.0.1:8000")
	if err!=nil{
		fmt.Println("net.Listen err=",err)
		return
	}

	//main退出前，关闭监听
	defer listener.Close()

	//堵塞等待用户连接
	conn,err1:=listener.Accept()
	if err1!=nil{
		fmt.Println("listener.Accept err1=",err1)
		return
	}

	defer conn.Close()

	buf:=make([]byte,1024)
	n,err2:=conn.Read(buf)  //读取对方发送的文件名
	if err2!=nil{
		fmt.Println("conn.Read err2=",err2)
		return
	}

	fileName:=string(buf[:n])

	//回复“ok”
	conn.Write([]byte("ok"))  //转换成字符串

	//接受文件内容
	RecvFile(fileName,conn)

}
