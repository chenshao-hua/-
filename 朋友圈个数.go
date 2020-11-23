/*
题目描述：
给定一个二维的0-1矩阵,如果第(i,j)位置是1,则表示第i个人和第j个人是朋友.已知朋友关系是可以
传递的,即如果a是b的朋友,b是c的朋友,那么a和c也是朋友,换言之这三个人处于同一个朋友圈之内.求
一共有多少个朋友圈.

示例 1：
Input:[[1,1,0],[1,1,0],[0,0,1]]
Output:2
在这个样例中,[1,2]处于一个朋友圈,[3]处于一个朋友圈.

示例 2：
Input:[[1,1,0],[1,1,1],[0,1,1]]
Output:1
已知学生0和学生1互为朋友，学生1和学生2互为朋友，所以学生0和学生2也是朋友，所以他们
三个在一个朋友圈，返回1

解题思路：
图的表示方法是,每一行(列)表示一个节点,每列或行表示是否存在一个相邻节点.因此有n个节点,
每个节点最多有n条边,表示和所有人都是朋友,最少可以有1条边,表示自己与自己相连.
*/

package main

import "fmt"

func findCircleNum(friends [][]int)int{
	n,count:=len(friends),0
	visited:=make([]bool,n)
	for i:=0;i<n;i++{
		if visited[i]==false{
			dfs(friends,i,visited)
			count++
		}
	}
	return count
}

func dfs(friends [][]int,i int,visited []bool){
	visited[i]=true
	for k:=0;k<len(friends);k++{
		if friends[i][k]==1&&!visited[k]{
			dfs(friends,k,visited)
		}
	}
}

func main(){
	fmt.Println("求朋友圈的个数")
	nums:=[][]int{{1,1,0},{1,1,1},{0,1,1}}
	fmt.Println(findCircleNum(nums))
}