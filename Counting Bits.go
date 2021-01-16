/*
Given a non negative integer number num.For every numbers i in the range 0<=i<=num
calculate the number of 1's in their binary representation and return  them as an array.
Example 1:
Input:2
Output:[0,1,1]

Example 2:
Input:5
Output:[0,1,1,2,1,2]

题目大意:
给定一个非负整数num.对于0<=i<=num范围中的每个数字i,计算二进制中的1数目并将它作为数组返回.

解题思路:
方法1:动态规划+最低有效位(去掉)
最直观的做法是利用二进制的思路,i向右移动一位之后有多少个1,并判断此时i的最后一位是否为1,即动态规划,
状态转移方程为:p(x)=p(x/2)+(x mod 2);

方法2:动态规划+最高有效位(去掉)
状态转移方程:P(x+b)=P(x)+1,b=2^m>x;
*/

package main

import "fmt"

func countBits(num int)[]int{
	ans:=make([]int,num+1)
	ans[0]=0
	for i:=1;i<=num;i++{
		ans[i]=i&1+ans[i>>1]
	}
	return ans
}

func countBits1(num int)[]int{
	ans:=make([]int,num+1)
	i,b:=0,1
	for b<=num{
		for i<b&&i+b<=num{//generate [b,2b) or [b,num) from [0,b)
			ans[i+b]=ans[i]+1
			i++
		}
		i=0
		b<<=1 //b=2b
	}
	return ans
}
func main(){
	fmt.Println(countBits(4))
}