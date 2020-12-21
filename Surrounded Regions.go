/*
Given a 2D board containing 'x' and 'o'(the letter O),capture all regions
surrounded by 'x'.
A region is captured by flipping all 'o's into 'x's in that surround region.

Example:
x x x x
x o o x
x x o x
x o x x

After running your function,the board should be:
x x x x
x x x x
x x x x
x o x x

Explanation:
Surrounded regions shouldn't be on the boarder,which means that any 'o' on the boarder
of the board are not flipped to 'x'.Any 'o' that is not on the border and it is not
connected to an 'o' on the border will be flipped to 'x'.Two cells are connected if
they are adjacent cells connected horizontally or vertically.

题目大意:
给定一个二维矩阵,包含字母'x'和'o'.找到所有被'x'包围的区域,并将这些区域里面所有的'o'用'x'进行填充.被包围的
区间的'o'用'x'进行填充.任何边界上的'o',且与边界上相连的都不会被填充为'x'.

利用DFS/BFS,先将边缘上的'o'标记为另外一个字母,然后再枚举所有的字符过程中,把剩下的'o'标记为'x'.
*/

package main

import "fmt"

var dir=[]int{-1,0,1,0,-1}

func solveSurroundedRegion(board [][]byte){
	for i:=range board{
		for j:=range board[i]{
			if (i==0||i==len(board)-1||j==0||j==len(board[i])-1)&&board[i][j]=='o'{
				DFSRegion(i,j,board)
			}
		}
	}

	for i:=range board{
		for j:=range board[i]{
			if board[i][j]=='*'{
				board[i][j]='o'
			}else if board[i][j]=='o'{
				board[i][j]='x'
			}
		}
	}
}

func DFSRegion(i,j int,board [][]byte){
	if i<0||i>len(board)-1||j<0||j>len(board[i])-1{
		return
	}
	if board[i][j]=='o'{
		board[i][j]='*'
		for k:=0;k<4;k++{
			DFSRegion(i+dir[k],j+dir[k+1],board)
		}
	}
}
func main(){
	fmt.Println("翻转包围的区域中的'o'")
	board:=[][]byte{{'x','x','x','x'},{'x','o','o','x'},{'x','x','o','x'},{'x','o','x','x'}}
	solveSurroundedRegion(board)
	fmt.Printf("%s",board)
}
