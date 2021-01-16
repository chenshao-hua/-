/*
Given a positive integer num,write a function which returns True if num is a perfect
square else False.
Note:Do not use any built-in library function such as sqrt.

Example 1:
Input:16
Output:true

Example 2:
Input:14
Output:false

题目大意:
判断给定的正整数是否为完全平方数.不能使用库自带的函数.

解题思路:
这道题用枚举法的时间复杂度是O(n),所以暂时不考虑.根据数组是有序的可以利用二分搜索来解答.
根据它的定义,是否能被开根号,即找到一个数的平方是否可以等于待判断的数字,从[1,n]区间内
进行二分,若能找到则返回true,否则false.
还有一个简单的方法是,根据数字公式推理得到,满足完全平方的数一定满足前n个奇数的和:
4=1+3;
9=1+3+5;
16=1+3+5+7;
*/

package main

import "fmt"

func isPerfectSquare(num int)bool{
	/*
	flag,l,r,board:=false,1,num>>1,0
	if num==1{
		return true;
	}
	for l<r{
		fmt.Println(l," ",r," ",board)
		if r*r==num{
			flag=true
			break
		}else if r*r<num{
			l,r=r,board
		}else{
			board=r
			r=l+(r-l)>>1
		}
	}
	return flag
	*/
	 /*可以较为简练点*/
	low,high,mid:=0,num,0
	for low<=high{
		mid=low+(high-low)>>1
		if mid*mid==num{
			return true
		}else if mid*mid<num{
			low=mid+1
		}else{
			high=mid-1
		}
	}
	return false
}

func isPerfectSquare1(num int)bool{
	i:=1
	for num>0{
		num-=i
		i+=2
	}
	return num==0
}
func main(){
	fmt.Println(isPerfectSquare(7))
	fmt.Println(isPerfectSquare1(7))
}