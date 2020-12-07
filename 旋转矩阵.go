/*
方法二:
原地进行旋转操作,在前面得到的规律是:m(row,col)=m(col,n-1-row),
因此先把m(col,n-1-row)临时存储到temp中,依次推进,得到循环.
其中处于循环中:
m[row][col];
m[col][n-1-row];
m[n-1-row][n-1-col];
m[n-col-1][row]

需要确定枚举的位置,当n为偶数时,(n/2)*(n/2)=n^2/4个位置,可以保证不重不漏;
n为奇数时,(n-1)/2*(n+1)/2=(n^2-1)/4个位置,可以做到不重不漏;

方法三:
原地双百,核心思路是用翻转代替旋转,先以对角线为轴,进行翻转.再以每一行的中点
为轴,进行翻转.
对角线翻转:
m[row][col]=m[col][row]
中心翻转:
m[row][col]=m[row][n-1-col]

*/

package main

import "fmt"

func rotatematrix1(matrix [][]int){
	if len(matrix)==0{
		return
	}
	n:=len(matrix)
	for row:=0;row<n/2;row++{
		for col:=0;col<(n+1)/2;col++{
			/*四个位置的元素进行互换*/
			temp:=matrix[n-1-col][row]
			matrix[n-1-col][row]=matrix[n-1-row][n-1-col]
			matrix[n-1-row][n-1-col]=matrix[col][n-1-row]
			matrix[col][n-1-row]=matrix[row][col]
			matrix[row][col]=temp
		}
	}
}

func rotatematrix2(matrix [][]int){
	if len(matrix)==0{
		return
	}
	n:=len(matrix)

	/*对角线翻转*/
	for row:=0;row<n;row++{
		for col:=row+1;col<n;col++{
			temp:=matrix[row][col]
			matrix[row][col]=matrix[col][row]
			matrix[col][row]=temp
		}
	}
	/*对每一行以中点进行翻转*/
	for row:=0;row<n;row++{
		for col:=0;col<n/2;col++{
			temp:=matrix[row][col]
			matrix[row][col]=matrix[row][n-1-col]
			matrix[row][n-1-col]=temp
		}
	}
}

func main(){
	fmt.Println("求旋转90度的矩阵")
	matrix:=[][]int{{1,2,3},{4,5,6},{7,8,9}}
	//rotatematrix1(matrix)
	rotatematrix2(matrix)
	fmt.Println(matrix)
}