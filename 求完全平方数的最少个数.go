/*
题目描述：
给定正整数，找到若干个完全平方数（比如1，4，9，16）使得它们的和等于n。你需要让组成和
的完全平方数的个数达到最少。

示例 1：
Input:n=12
Output:3
说明：12=4+4+4

示例 2：
Input:13
Output:2
说明：13=4+9

解题思路：
这道题首先想到的是动态规划，当n=1时，最少只需要1个完全平方数1即可。因此dp[i]:表示
完全平方和为i的最小个数初始状态dp[i]均取最大值i，即1+1+1...+1，i个1；dp[0]=0
转移方程：dp[i]=min(dp[i],dp[i-j*j]+1),其中，j是平方数，j=1~k，其中k*k要
保证<=i。简而言之，完全平方数和为i的最大个数与（完全平方数和为i-j*j的最小个数+完全
平方和为j*j的最小个数）可以看到dp[j*j]是等于1的。
*/

package main

import "fmt"

func numSquare(n int)int{
	dp:=make([]int,n+1)
	for i:=1;i<=n;i++{
		dp[i]=i
		for j:=1;i-j*j>=0;j++{
			dp[i]=min(dp[i],dp[i-j*j]+1)
		}
	}
	return dp[n]
}

func min(x,y int)int{
	if x<y{
		return x
	}else{
		return y
	}
}

func main(){
	fmt.Println("求完全平方数的最小个数")
	n:=10
	fmt.Println(numSquare(n))
}