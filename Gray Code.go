/*
The gray code is a binary numeral system where two
successive values differ in only one bit.Given a
non=negative integer n representing the total number
of bits in the code,print the sequence of gray code.
A gray code sequence must begin with 0.

Example 1:
Input:2
Output:[0,1,3,2]

Explanation:
00-0
01-1
11-3
10-2

Example 2:
Input:0
Output:[0]

题目:
格雷编码用在一个二进制数字系统里面.在该系统中,两个连续的数值仅有一个
位数(在二进制中)的差异.给定一个代表编码总位数的非负整数n,输出其格雷
编码序列必须是以0开头.

格雷码的处理主要是位操作Bit Operation.

*/

package main

import "fmt"

func grayCode(n int)[]int{
	var m uint=1<<uint(n)
	ans:=make([]int,m)
	for i:=uint(0);i<m;i++{
		ans[i]=int((i>>1)^i)
	}
	return ans
}

func generategraycode(n int)[]int{
	if n==0{
		return []int{0}
	}
	res:=[]int{}
	num:=make([]int,n) /*存二进制*/
	generatebracktrace(int(1<<uint(n)),0,&num,&res)
	return res
}

func generatebracktrace(n,step int,num *[]int,res *[]int){
	if n==0{
		return
	}
	*res=append(*res,converBinary(*num))

	if step%2==0{
		(*num)[len(*num)-1]=fligGrayCode((*num)[len(*num)-1])
	}else{
		index:=len(*num)-1
		for ;index>=0;index--{
			if (*num)[index]==1{
				break
			}
		}
		if index==0{
			(*num)[len(*num)-1]=fligGrayCode((*num)[len(*num)-1])
		}else{
			(*num)[index-1]=fligGrayCode((*num)[index-1])
		}
	}
	generatebracktrace(n-1,step+1,num,res)
	return
}

func converBinary(num []int)int{
	res,rad:=0,1
	for i:=len(num)-1;i>=0;i--{
		res+=num[i]*rad
		rad*=2
	}
	return res
}

func fligGrayCode(num int)int{
	if num==0{
		return 1
	}
	return 0
}
func main(){
	fmt.Println("输出格雷编码序列")
	fmt.Println(grayCode(4))
	fmt.Println(generategraycode((4)))
}