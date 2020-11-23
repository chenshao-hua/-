/*
题目描述:
给定一个正整数n和一个整数k，求在1到n中选取k个数字的所有组合方法。

示例：
Input:n=4,k=2
Output:[[2,4],[3,4],[2,3],[1,2],[1,3],[1,4]]
这里二维数组的每个维度都可以以任意顺序输出

解题思路:
利用简单的回溯法即可
*/

package main

import "fmt"

func combine(n,k int)(ans [][]int){
	comb:=make([]int,k)
	count:=0
	backtracking(&ans,comb,count,1,n,k)
	return
}

func backtracking(ans *[][]int,comb []int,count,pos,n,k int){
	if count==k{
		/*切片做函数参数时,append增加元素时,相当于创建一个新的变量,因此用指针传递*/
		*ans=append(*ans,append([]int{},comb...)) /*"..."在切片或数组是打散,变成单个*/
		return
	}
	for i:=pos;i<=n;i++{
		comb[count]=i
		count++
		backtracking(ans,comb,count,i+1,n,k)
		count--
	}
}
func main(){
	fmt.Println("求k个数字的所有组合方法")
	fmt.Println(combine(4,2))
}
