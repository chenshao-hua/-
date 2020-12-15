package main

import (
	"fmt"
	"strconv"
)

func readBinaryWatch(n int)(res []string){
	time:=[][]int{{0,0}}
	nums:=[]int{1,2,4,8,1,2,4,8,16,32}
	watchofbfs(nums,&time,0,n,&res)
	return
}

func watchofbfs(nums []int,time *[][]int,index,num int,res *[]string){
	if num==0{
		if (*time)[0][0]>11||(*time)[0][1]>59{
			return
		}
		hour:=strconv.Itoa((*time)[0][0])
		minute:=strconv.Itoa((*time)[0][1])
		if len(minute)==1{
			minute="0"+minute
		}
		*res=append(*res,hour+":"+minute)
		return
	}
	for i:=index;i<10;i++{
		temp:=[]int{0,0}
		temp[0]=(*time)[0][0]
		temp[1]=(*time)[0][1]
		if i<4{
			(*time)[0][0]+=nums[i]
		}else{
			(*time)[0][1]+=nums[i]
		}
		watchofbfs(nums,time,i+1,num-1,res)
		(*time)[0][0]=temp[0]
		(*time)[0][1]=temp[1]
	}
}

func main(){
	fmt.Println("求二进制表所有的可能组合")
	fmt.Println(readBinaryWatch(1))
}
