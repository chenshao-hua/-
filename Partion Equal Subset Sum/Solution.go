package main

import (
	"fmt"
	"math"
)

func canPartition(nums []int)bool{
	flag:=false
	sum,temp:=0,0
	for _,num:=range nums{
		sum+=num
	}
	if sum%2!=0{//sum为奇数,直接返回false
		return false
	}
	dfs(nums,sum/2,0,0,&temp)
	if(temp==sum/2){
		flag=true
	}
	return flag
}

func dfs(nums []int,sum int,index int,ans int,temp *int){
	if index>=len(nums){
		return
	}
	if ans==sum{
		*temp=sum
		return
	}
	for i:=index;i<len(nums)&&(*temp)!=sum;i++{//剪枝(*temp)!=sum、ans+nums[i]>sum
		if ans+nums[i]>sum{
			continue
		}
		ans+=nums[i]
		fmt.Println(ans," ",sum)
		dfs(nums,sum,i+1,ans,temp)
		ans-=nums[i]
	}
}


func canPartitionOne(nums []int)bool{
	sum:=0
	maxNum:=math.MinInt64
	for _,num:=range nums{
		sum+=num
		maxNum=Max(maxNum,num)
	}
	target:=sum>>1
	if sum%2!=0||target<maxNum{//sum为奇数,直接返回false
		return false
	}
	if target==maxNum{
		return true
	}
	dp:=make([]int,target+1)
	dp[0]=1//初始化key为0时,value为1个
	for _,i:=range nums{
		for j:=target;j>=i;j--{
			dp[j]+=dp[j-i]
		}
		if dp[target]!=0{//表示已经找到一组子集满足条件
			return true
		}
	}
	return false
}

func Max(a,b int)int{
	if a>b{
		return a
	}
	return b
}
func main(){
	nums:=[]int{14,9,8,4,3,2,4,6}
	//fmt.Println(canPartition(nums))
	fmt.Println(canPartitionOne(nums))
}