/*
思路分析
其实没啥更好的解法,就是DFS深度优先搜索找结果,遍历格子,如果发现'.',
就开始执行下面的操作:从1到9依次填数,从填1开始,然后看下行有没有问题,
看下列有没有问题,看下3*3的子格子有没有问题,都没问题就递归的往下找.
有问题(1,2,3当前格子填的数字冲突了,或者4当前格子的填数导致后面递归
的填数失败了)就把这个位置换回'.'.
这就是一个回溯的过程,因为这样一来之前递归的失败路径就全都回退了,然
后改成填2,再继续遍历,如果1-9都遍历完,还是没有合适的,就返回false给上层.
代码实现
总之就是一个DFS搜索,注意下1,2,3条件的判断,然后想清楚什么时候递归(当前填
数没问题,要确认下面层次的问题)以及递归的出口(当前位置1-9都遍历完还是没有合
适的就返回false,如果9*9的格子全遍历完了中间没有返回false就说明数组中没有'.'了,
填满了)就行了.

*/

package main

import "fmt"

func solveSudoku(board [][]byte){
	backtrack(board)
}

func backtrack(board [][]byte)bool{
	for i:=0;i<9;i++{
		for j:=0;j<9;j++{
			if board[i][j]=='.'{
				for k:=0;k<9;k++{
					board[i][j]=byte('1'+k)
					if isValid(board,i,j)&&backtrack(board){
						return true
					}else{
						board[i][j]='.'
					}
				}
				return false
			}
		}
	}
	return true
}

func isValid(board [][]byte,x,y int)bool{
	for i:=0;i<len(board);i++{
		if (i!=x&&board[i][y]==board[x][y])||(i!=y&&board[x][i]==board[x][y]){
			return false
		}
	}
	for i:=0;i<3;i++{
		for j:=0;j<3;j++{
			pos_x:=x-x%3+i
			pos_y:=y-y%3+j
			if x!=pos_x&&y!=pos_y&&board[x][y]==board[pos_x][pos_y]{
				return false
			}
		}
	}
	return true
}
func main(){
	fmt.Println("leetcode-47:求独解")
	board:=[][]byte{{'5','3','.','.','7','.','.','.','.'},
		            {'6','.','.','1','9','5','.','.','.'},
		            {'.','9','8','.','.','.','.','6','.'},
		            {'8','.','.','.','6','.','.','.','3'},
		            {'4','.','.','8','.','3','.','.','1'},
		            {'7','.','.','.','2','.','.','.','6'},
		            {'.','6','.','.','.','.','2','8','.'},
		            {'.','.','.','4','1','9','.','.','5'},
		            {'.','.','.','.','8','.','.','7','9'}}
	solveSudoku(board)
    fmt.Printf("%c",board)
}