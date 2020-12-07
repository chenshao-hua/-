package main

import "fmt"

func spiralOrder(matrix [][]int)(ans []int){
	if len(matrix)==0{
		return
	}
	/*当前层的行、列的最小、最大坐标*/
	Minrow,Maxrow,Mincol,Maxcol:=0,len(matrix)-1,0,len(matrix[0])-1
	for ;Minrow<=Maxrow&&Mincol<=Maxcol;{
		/*遍历当前层上面边的所有元素坐标,行坐标不变,纵坐标从Mincol到Maxcol*/
		for col:=Mincol;col<=Maxcol;col++{
			ans=append(ans,matrix[Minrow][col])
		}
		/*遍历当前层右面边的所有元素坐标,列坐标不变,行坐标从Minrow+1到Maxrow*/
		for row:=Minrow+1;row<=Maxrow;row++{
			ans=append(ans,matrix[row][Maxcol])
		}
		/*满足4条边*/
		if Minrow<Maxrow&&Mincol<Maxcol{
			/*遍历当前层下面边的所有元素坐标,行坐标不变,纵坐标Maxcol-1到Mincol*/
			for col:=Maxcol-1;col>=Mincol;col--{
				ans=append(ans,matrix[Maxrow][col])
			}
			/*遍历当前层左面边的所有元素坐标,列坐标不变,行左标从Maxrow-1到Minrow+1*/
			for row:=Maxrow-1;row>=Minrow+1;row--{
				ans=append(ans,matrix[row][Mincol])
			}
		}
		Minrow++
		Maxrow--
		Mincol++
		Maxcol--
	}
	return
}
func main(){
	fmt.Println("求螺旋矩阵")
	matrix:=[][]int{{1,2,3,4},{5,6,7,8},{9,10,11,12}}
	fmt.Println(spiralOrder(matrix))
}
