/*
A message containing letters from A-Z is being encoded to
numbers using the following mapping:
'A'->1
'B'->2
...
'Z'->26

Given a non-empty string containing only digits,determine the total number
of ways to decode it.

Example 1:
Input:"12"
Output:2
Explanation:It could be decoded as "AB"(1 2) or "L"(12).

Example 2:
Input:"226"
Output:3
Explanation:It could be decoded as "BZ"(2 26),"VF"(22 6),or "BBF"(2 2 6).

解题思路:
这道题的意思是给定一个数字型字符串,计算出编码方法的总数.
这道题选用动态规划的方法.dp[n]保存的是编码长度为n个字符的字符串方法总数.考虑到给定的字符串中
可能包含'0',因此需要跳过.dp[0]代表空字符串,只有一种编译方法,dp[0]=1.dp[1]需要考虑原字符串
是否以'0'开头,dp[1]=0，否则dp[1]=1.
状态转移方程为:
1<=s[i-1:i]<=9,dp[i]+=dp[i-1];
10<=s[i-2:i]<=26,dp[i]+=dp[i-2];

*/

package main

import (
	"fmt"
	"strconv"
)

func decodeway(str string)int{
	if len(str)==0{
		return 0
	}
	dp:=make([]int,len(str)+1)
	dp[0]=1
	if str[:1]=="0"{
		dp[1]=0
	}else{
		dp[1]=1
	}
	for i:=2;i<=len(str);i++{
		lastNum,_:=strconv.Atoi(str[i-1:i])
		if lastNum>=1&&lastNum<=9{
			dp[i]+=dp[i-1]
		}
		lastNum,_=strconv.Atoi(str[i-2:i])
		if lastNum>=10&&lastNum<=26{
			dp[i]+=dp[i-2]
		}
	}
	return dp[len(str)]
}
func main(){
	fmt.Println("求编码的总数")
	str:="226"
	fmt.Println(decodeway(str))
}