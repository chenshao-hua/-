/*
A character in UTF8 can be from 1 to 4 bytes long,subjected to the following rules:
1.For 1-byte character,the first bit is a 0,followed by its unicode code.
2.For n-bytes character,the first n-bits are all one's,the n+1 bit is 0,followed by
n-1 bytes with most significant 2 bits being 10.
0xxxxxxx
110xxxxx 10xxxxxx
1110xxxx 10xxxxxx 10xxxxxx
11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

Given an array of integers representing the data,return whether it it a valid utf-8
encoding.
Note:The input is an array of integers.Only the least significant 8 bits of each integer
is used to store the data.This means each integer represents only 1 byte of data.

Example 1:
Input:data=[197,130,1],which represents the octet sequence:11000101 10000010 00000001
Output:true
It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.

Example 2:
Input:data=[235,140,4],which represents the octet sequence:11101011 10001100 00000100
Output:false
The first 3 bits are all one's and the 4th bit is a means it is a 3-bytes character.
The next byte is a continuation byte which starts with 10 and that's correct.But the
second continuation byte does not start with 10,so it is invalid.
题目大意:
UTF-8中的一个字符可能的长度为1到4字节,遵循以下的规则:
对于1字节的字符,字节的第一位设为0,后面7位为这个符号的unicode码;
对于n字节的字符(n>1),第一个字节的前n位都设为1,第n+1位设为0,后面字节的前两位一律设为10.剩下的没有提及
的二进制位,全部为这个符号的unicode码;
给定一个表示数据的整数数组,返回它是否为有效的utf-8编码.
注意:
输入是整数数组.只有每个整数的最低8个有效位用来存储数据.这意味着每个整数只表示1字节的数据.

解题思路:
这道题看起来很复杂,其实严格按照UTF8的定义来模拟就可以了.范围是在1-4个字节内,自然而然就
想到数组里面的整数必须要落在指定的范围内.此外定义一个count变量计数,表示后面的个数.
*/

package main

import "fmt"

func validUtf8(data []int)bool{
	count:=0
	for _,num:=range data{
		if count==0{
			if num>=248{
				return false //11111000=248超过最大值
			}else if num>=240{
				count=3      //11110000=240
			}else if num>=224{
				count=2      //11100000=224
			}else if num>=192{
				count=1      //11000000=192
			}else if num>127{
				return false //01111111=127不在此范围
			}
		}else{
			if num<=127||num>=192{
				return false
			}
			count-- //落在10xxxxxx,范围为128<=num<192
		}
	}
	return count==0
}

func main(){
	data:=[]int{197,130,1}
	fmt.Println(validUtf8(data))
}