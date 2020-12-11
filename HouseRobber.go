package main

import "fmt"

func houseRobber(nums []int)int{
	if len(nums)==0{
		return 0
	}
	n:=len(nums)
	if n==1{
		return nums[0]
	}
    /*cur当前的*/
	pre1,pre2,cur:=0,0,0
	for i:=0;i<n;i++{
		cur=findmax(pre1+nums[i],pre2)
		pre1=pre2
		pre2=cur
	}
	return cur
}

func findmax(a,b int)int{
	if a>=b{
		return a
	}
	return b
}
func main(){
	fmt.Println("求劫匪能抢劫多少")
	nums:=[]int{2,7,9,3,1}
	fmt.Println(houseRobber(nums))
}
