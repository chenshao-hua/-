/*
Given a string containing only digits,restore it by returning all possible valid IP address
combinations.

Example 1:
Input:"25525511135"
Output:["255.255.11.135","255.255.111.35"]

解题思路:
IP每一段的数字范围是:0~255,不可以超过此范围,而且第一段不能为0,可以使用DFS进行搜索,
深度满足4时,进行返回
*/
package main

import (
	"fmt"
	"strconv"
)

func restoreIPAddresses(s string)[]string{
	res,ip:=make([]string,0),make([]int,0)
	if len(s)<4||len(s)>12{
		res=append(res,s)
		return res
	}
	DFS(s,0,ip,&res)
	return res
}

func DFS(s string,index int,ip []int,res *[]string){
	if index==len(s){
		if len(ip)==4{
			*res=append(*res,getstring(ip))
		}
		return
	}

	if index==0{
		num,_:=strconv.Atoi(string(s[0]))
		ip=append(ip,num)
		DFS(s,index+1,ip,res)
	}else{
		num,_:=strconv.Atoi(string(s[index]))
		next:=ip[len(ip)-1]*10+num
		if next<=255&&ip[len(ip)-1]!=0{
			fmt.Println(ip)
			ip[len(ip)-1]=next
			DFS(s,index+1,ip,res)
			ip[len(ip)-1]/=10
		}
		if len(ip)<4{
			ip=append(ip,num)
			DFS(s,index+1,ip,res)
			ip=ip[:len(ip)-1]
		}
	}
}

func getstring(ip []int)string{
	res:=strconv.Itoa(ip[0])
	for i:=1;i<len(ip);i++{
		res+="."+strconv.Itoa(ip[i])
	}
	return res
}

func main(){
	fmt.Println("求所有可能的IP地址格式")
	s:="25525511135"
	fmt.Printf("%+v",restoreIPAddresses(s))
}