/*
题目描述:
给定一个二维的非负整数矩阵,每个位置的值表示海拔高度.假设左边和上边是太平洋,右边和下边是
大西洋,求从哪个位置向下流水,可以流到太平洋和大西洋.水只能从海拔高的位置流到海拔低或者相同
的位置.

示例：
Input:[[1,2,2,3,(5)],
      [3,2,3,(4),(4)],
      [2,4,(5),3,1],
      [(6),(7),1,4,5],
      [(5),1,1,2,4]]
Output:[[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
在这个案例中,有括号的区域为满足条件的位置.

解题思路:
回溯法.这道题目要求的是满足向下流能够达到两个大洋的位置.若我们对所有的位置进行搜索,那么在不剪枝
的情况下,时间复杂度会很大.因此,可以采用逆向思维的方式进行,从两个大洋开始往上流,这样只需要
对矩阵的四条边进行搜索,搜索完成后,只需要遍历一次矩阵,满足条件的位置即为两大洋向上流都能
到达的位置.
*/

package main

import "fmt"

func pacificAtlantic(matrix [][]int)(ans [][]int){
	if len(matrix)==0||len(matrix[0])==0{
		return
	}
	m,n:=len(matrix),len(matrix[0])
	reach_p,reach_a:=make([][]bool,m),make([][]bool,m)
	for i:=range reach_p{
		reach_p[i]=make([]bool,n)
	}
	for i:=range reach_a{
		reach_a[i]=make([]bool,n)
	}
	for i:=0;i<m;i++{
		dfs(matrix,reach_p,i,0)
		dfs(matrix,reach_a,i,n-1)
	}
	for i:=0;i<n;i++{
		dfs(matrix,reach_p,0,i)
		dfs(matrix,reach_a,m-1,i)
	}

	for i:=0;i<m;i++{
		for j:=0;j<n;j++{
			if reach_a[i][j]&&reach_p[i][j]{
				temp:=[]int{i,j}
				ans=append(ans,temp)
			}
		}
	}
	return
}

func dfs(matrix [][]int,reach [][]bool,r,c int){
	if reach[r][c]==true{
		return
	}
	direction:=[]int{-1,0,1,0,-1}
	reach[r][c]=true
	x,y:=0,0
	for i:=0;i<4;i++{
		x,y=r+direction[i],c+direction[i+1]
		if x>=0&&x<len(matrix)&&y>=0&&y<len(matrix[0])&&matrix[r][c]<=matrix[x][y]{
			dfs(matrix,reach,x,y)
		}
	}
}
func main(){
	fmt.Println("求流向太平洋、大西洋的位置")
	nums:=[][]int{{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}}
	fmt.Println(pacificAtlantic(nums))
}