package main

import "fmt"

func IslandNums(grid [][]byte)int{
	num:=0
	for i:=0;i<len(grid);i++{
		for j:=0;j<len(grid[0]);j++{
			if grid[i][j]=='1'{
				backtrack(grid,i,j)
				num++
			}
		}
	}
	return num
}

func backtrack(grid [][]byte,i,j int){
	if i<0||i>=len(grid)||j<0||j>=len(grid[0])||grid[i][j]=='0'{
		return
	}
	grid[i][j]='0'
	backtrack(grid,i-1,j)
	backtrack(grid,i+1,j)
	backtrack(grid,i,j-1)
	backtrack(grid,i,j+1)
}
func main(){
	fmt.Println("求岛屿的数量")
	grid:=[][]byte{{'1','1','0','0','0'},
		           {'1','1','0','0','0'},
		           {'0','0','1','0','0'},
		           {'0','0','0','1','1'}}
	fmt.Println(IslandNums(grid))
}
