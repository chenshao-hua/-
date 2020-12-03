package main

import "fmt"

func maxAreaOfIsland(grid [][]int)int{
	maxArea:=0
	if len(grid)==0||len(grid[0])==0{
		return 0
	}
	for i:=0;i<len(grid);i++{
		for j:=0;j<len(grid[0]);j++{
			if grid[i][j]==1{
				maxArea=Max(maxArea,dfs(grid,i,j))
			}
		}
	}
	return maxArea
}

func dfs(grid [][]int,r,c int)int{
	area:=1
	if grid[r][c]==0{
		return 0
	}
	grid[r][c]=0
	direction:=[]int{-1,0,1,0,-1}
	for i:=0;i<4;i++{
		x,y:=r+direction[i],c+direction[i+1]
		if x>=0&&x<len(grid)&&y>=0&&y<len(grid[0]){
			area+=dfs(grid,x,y)
		}
	}
	return area
}

/*方法二*/
func maxArea(grid [][]int)int{
	maxArea:=0
	for i:=0;i<len(grid);i++{
		for j:=0;j<len(grid[0]);j++{
			if grid[i][j]==1{
				maxArea=Max(maxArea,backtrack(grid,i,j))
			}
		}
	}
	return maxArea
}

func backtrack(grid [][]int,i,j int)int{
	/*不是岛屿*/
	if i<0||i>=len(grid)||j<0||j>=len(grid[0])||grid[i][j]==0{
		return 0
	}
	/*遍历过的岛屿,标记为0*/
	grid[i][j]=0
	num:=1
	num+=backtrack(grid,i-1,j)
	num+=backtrack(grid,i+1,j)
	num+=backtrack(grid,i,j-1)
	num+=backtrack(grid,i,j+1)
	return num
}

func Max(a,b int)int{
	if a>b{
		return a
	}else{
		return b
	}
}

func main(){
	fmt.Println("求最大岛屿的面积")
	grid:=[][]int{{1,0,1,1,0,1,0,1}, {1,0,1,1,0,1,1,1}, {0,0,0,0,0,0,0,1}}
	fmt.Println(maxAreaOfIsland(grid))
}
