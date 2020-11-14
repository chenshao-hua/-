/*
题目描述：
编写一个程序，输入一个整数，求出该整数的各位数字之和。

示例：
Input:num=1234
Output:10(1+2+3+4)

解题思路：
这个主要是弄明白一个简单的数学问题，然后可以根据除以10求余得到每一个数字，并借助整除10；
*/

package main

import "fmt"

func digitSum(num int)(sum int){
	sum=0
	for num!=0{
		sum+=num%10 /*得到尾部数字*/
		num/=10     /*去掉尾部数字*/
	}
	return
}

func main(){
	fmt.Println("输入整数，求各位数字之和")
	num:=345
	fmt.Println(digitSum(num))
}
