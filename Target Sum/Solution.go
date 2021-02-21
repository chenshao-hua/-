package main

import "fmt"

//dfs
func findTargetSumWays(nums []int ,S int)int{
	ans:=0
	dfs(nums,S,0,&ans)
	return ans
}

func dfs(nums []int,S,k int,ans *int){
	if k>len(nums)||(S!=0&&k==len(nums)){//递归返回
		return
	}
	if S==0&&k==len(nums){
		*ans=*ans+1
		return
	}
	if k<len(nums){//保证索引不越界
		board:=[]int{-nums[k],nums[k]}
		for i:=0;i<2;i++{
			S-=board[i]
			dfs(nums,S,k+1,ans)
			S+=board[i]
		}
	}
}

//dfs+剪枝优化

func findTargetSumWaysOne(nums []int,S int)int{
	//sums[i]存储的是后缀和nums[i:],即从i到结尾的和,进行剪枝优化
	sums:=make([]int,len(nums))
	sums[len(nums)-1]=nums[len(nums)-1]
	for i:=len(nums)-2;i>=0;i--{
		sums[i]=sums[i+1]+nums[i]
	}
	ans:=0
	dfsOne(nums,0,0,S,&ans,sums)
	return ans
}

func dfsOne(nums []int,index,curSum,S int,ans *int,sums []int){
	if index==len(nums){
		if curSum==S{
			*ans=*ans+1
		}
		return
	}
	//剪枝优化:若sums[index]的值小于剩下需要正数的值,那么右边就算都是+号也无能为力
	if S>curSum+sums[index]{
		return
	}
	dfsOne(nums,index+1,curSum+nums[index],S,ans,sums)
	dfsOne(nums,index+1,curSum-nums[index],S,ans,sums)
}

//动态规划
func findTargetSumWaysTwo(nums []int,S int)int{
	total:=0
	for _,n:=range nums{
		total+=n
	}
	if S>total||(S+total)%2==1{
		return 0
	}
	target:=(S+total)>>1
	dp:=make([]int,target+1)
	dp[0]=1
	for _,j:=range nums{
		for i:=target;i>=j;i--{
			dp[i]+=dp[i-j]
		}
	}
	return dp[target]
}
func main(){
	nums,S:=[]int{1,1,1,1,1},3
	fmt.Println(findTargetSumWays(nums,S))
	fmt.Println(findTargetSumWaysOne(nums,S))
	fmt.Println(findTargetSumWaysTwo(nums,S))
}
