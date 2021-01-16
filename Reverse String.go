/*
Write a function that reverses a string.The input string is given as an array of characters
char[].Do not allocate extra space for another array,you must do this by modifying the
input array in-place with O(1) extra memory.
You may assume all the characters consist of printable ascii characters.

Example 1:
Input:["h","e","l","l","o"]
Output:["o","l","l","e","h"]

Example 2:
Input:["H","a","n","n","a","h"]
Output:["h","a","n","n","a","H"]

题目大意:
翻转数组,空间复杂度为O(1).
利用左右双指针进行遍历,不断交换左右两边的元素.
*/

package main

import "fmt"

func reverseString(s []byte)[]byte{
	l,r:=0,len(s)-1
	for l<r{
		s[l],s[r]=s[r],s[l]
		l++
		r--
	}
	return s
}
func main(){
	s:=[]byte{'h','e','l','l','o'}
	fmt.Printf("%v",reverseString(s))
}