/*
Write a program to check whether a given number is an ugly number.
Ugly numbers are positive number whose prime factors only include 2,3,5.
Number '1' is typically treated as an ugly number.

Example 1:
Input:6
Output:true
Explanation:6=2x3

Example 2:
Input:8
Output:true
Explanation:8=2x2x2

Example 3:
Input:14
Output:false
Explanation:14 is not ugly since it includes another prime factor 7.

题目大意:
判断一个数字是否为丑陋数字,丑陋数字因子只包含2,3,5.

解题思路:
这道题没什么难度,根据题目意思来做就行.
 */


package main

import "fmt"

func isUgly(num int)bool{
	for {
		if num<1{
			break
		}
		if num==1{
			return true
		}
		if num%2==0{
			num/=2
		}else if num%3==0{
			num/=3
		}else if num%5==0{
			num/=5
		}else{
			return false
		}
	}
	return false
}

func isUglyOne(num int) bool{
	for i:=2;i<6&&num>0;i++{
		for num%i==0{
			num/=i
		}
	}
	return num==1
}
func main() {
	num:=15
	fmt.Println(isUgly(num))
	fmt.Println(isUglyOne(num))
}
