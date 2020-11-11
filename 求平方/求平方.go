/*
题目描述：
给定一个非负整数，求它的开方，向下取整

示例：
Input:8
Output:2

解题思路：
解法一：可以理解为，给定一个非负整数a，求f(x)=x^2-a=0的解，只考虑到x>=0，因此f(x)在定义域上是单调递增的。
所以f(a)=a^2-a>=0，因此可以对[0,a]区间使用二分查找的f(x)=0的解。
解法二：牛顿迭代法，其公式为Xn+1=Xn-F(Xn)f'(Xn)，给定f(x)=x^2-a，迭代公式为Xn+1=(Xn+a/Xn)/2
*/


package main

import "fmt"

func SquareOne(Num int)  int{
	if Num==0{
		return Num
	}
	L,R,Mid,Temp:=1,Num,0,0
	for{
		Mid=L+(R-L)/2
		Temp=Num/Mid
		if Temp==Mid{
			return Mid
		}else if Mid>Temp{
			R=Mid-1
		}else{
			L=Mid+L
		}
		if L>R{
			break
		}
	}
	return R
}

func SquareTwo(Num int) int{
	x:=Num
	for{
		x=(x+Num/x)/2
		if x*x<=Num{
			break
		}
	}
	return x
}

func main(){
	fmt.Println("*****求平方******")
	num:=8
	fmt.Println(SquareOne(num))
	fmt.Println(SquareTwo(num))
}
