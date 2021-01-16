/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Input:"hello"
Output:"holle"

Example 2:
Input:"leetcode"
Output:"leotcede"

题目大意:
求反转字符串中的元音字母.需要注意字母大小写.
利用双指针,不断进行交换.
*/

package main

import "fmt"

func reverseVowels(s string)string{
	str:=[]byte(s)
	l,r:=0,len(s)-1
	for l<r{
		if isVowels(str[l])&&isVowels(str[r]){
			str[l],str[r]=str[r],str[l]
		}else if isVowels(str[l])&&!isVowels(str[r]){
			r--
			continue
		}else if !isVowels(str[l])&&isVowels(str[r]){
			l++
			continue
		}
		l++
		r--
	}
	s=string(str[:])
	return s
}

func isVowels(s byte)bool{
	if s=='a'||s=='A'||s=='e'||s=='E'||s=='i'||s=='I'||s=='o'||s=='O'||s=='u'||s=='U'{
		return true
	}
	return false
}
func main(){
	s:="hello"
	fmt.Println(reverseVowels(s))
}