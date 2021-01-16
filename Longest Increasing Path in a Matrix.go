/*
Given an integer matrix,find the length of the longest increasing path.
Fro each cell,you can either move to four directions:left,right,up or down.You may NOT
move diagonally or move outside of the boundary(i.e.Wrap-around is not allowed).

Example 1:
Input:nums=[[9,9,4],
            [6,6,8],
            [2,1,1]]
Output:4
Explanation:The longest increasing path is [1,2,6,9]

Example 2:
Input:nums=[[3,4,5],
            [3,2,6],
            [2,2,1]]
Output:4
Explanation:The longest increasing path is [3,4,5,6].Moving diagonally is not allowed.
题目大意:
给定一个整数矩阵,找出最长递增路径的长度,对应每个单元格,可以进行左右上下移动,不可以在对角线上进行移动或者
移动到边界外(即不允许环绕).

解题思路:
这道题思路很清晰,可以利用DFS即可,并且利用记忆化进行处理,将搜索过的最大长度储存起来.利用cache二维数组对
每个单元最长递增路径的长度进行存储.
*/

package main

import (
	"fmt"
	"math"
)

var d =[][]int{{-1,0},{0,1},{1,0},{0,-1}}

func longestIncreasingPath(nums [][]int)int{
	/*初始化cache*/
	cache,res:=make([][]int,len(nums)),0
	for i:=0;i<len(cache);i++{
		cache[i]=make([]int,len(nums[0]))
	}

	/*dfs搜索并存储*/
	for i,v:=range nums{
		for j:=range v{
			searchPath(nums,cache,math.MinInt64,i,j)
			res=maxPath(res,cache[i][j])
		}
	}
	return res
}

func maxPath(a,b int)int{
	if a>b{
		return a
	}
	return b
}
func searchPath(board,cache [][]int,lastNum,x,y int)int{
	if board[x][y]<=lastNum{
		return 0
	}
	if cache[x][y]>0{
		return cache[x][y]
	}
	count:=1
	for i:=0;i<4;i++{
		nx,ny:=x+d[i][0],y+d[i][1]
		if isInIntBoard(board,nx,ny){
			count=maxPath(count,searchPath(board,cache,board[x][y],nx,ny)+1)
		}
	}
	cache[x][y]=count
	return count
}

func isInIntBoard(board [][]int,x,y int)bool{
	return x>=0&&x<len(board)&&y>=0&&y<len(board[0])
}
func main(){
	nums:=[][]int{{3,4,5},{3,2,6},{2,2,1}}
	fmt.Println(longestIncreasingPath(nums))
}