package main

import (
	"fmt"
	"strings"
)

func findMaxForm(strs []string,m int,n int)int{
	dp:=make([][]int,m+1)
	for i:=0;i<m+1;i++{
		dp[i]=make([]int,n+1)
	}
	//m个0,n个1
	for _,s:=range strs{
		//每个字符串中0和1的个数
		zero:=strings.Count(s,"0")
		one:=len(s)-zero
		if zero>m||one>n{
			continue
		}
		for i:=m;i>=zero;i--{
			for j:=n;j>=one;j--{
				dp[i][j]=max(dp[i][j],1+dp[i-zero][j-one])
			}
		}
	}
	return dp[m][n]
}

func max(a,b int)int{
	if a>b{
		return a
	}else{
		return b
	}
}

func main(){
	strs:=[]string{"111","1000","1000","1000"}
	m,n:=9,3
	fmt.Println(findMaxForm(strs,m,n))
}
