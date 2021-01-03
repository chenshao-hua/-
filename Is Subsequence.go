/*
Given a string s and a string t,check if s is subsequence of t.
You may assume that there is only lower case English letters in both s and t.t is
potentially a very long(length-=500,000)string and s is a short string(<=100).
A subsequence of a string is a new string which is formed from the original string
by deleting some(can be none)of the characters without disturbing the relative
positions of the remaining characters.(ie,"ace" is a subsequence of "abcde" while
"aec" is not).

Example 1:
Input:s="abc",t="ahbgdc"
Output:true

Example 2:
Input:s="axc",t="ahbgdc"
Output:false

题目大意:
给定字符串s和t,判断s是否为t的子序列,这个子序列是原始字符串删除一些(或者不删除)的字符而不改变剩余字符
相对位置形成的新字符.

解题思路:
方法1:
可以直接使用贪心算法.注意需要保持s字母的顺序.

 */

package main

import "fmt"

func isSubsequence(s,t string)bool{
	if len(s)==0{
		return true
	}
	ans,i,j:=false,0,0
	for ;i<len(t)&&j<len(s);i++{
		if t[i]==s[j]{
			j++
		}
		if j>=len(s){
			return true
		}
	}
	return ans
}

func IsSubsequence(s,t string)bool{
	for len(s)>0&&len(t)>0{
		if s[0]==t[0]{
			s=s[1:]
		}
		t=t[1:]
	}
	return len(s)==0
}

func IsSub(s,t string)bool{
	index,flag:=0,false
	for i:=0;i<len(s);i++{
		flag=false
		for ;index<len(t);index++{
			if s[i]==t[index]{
				flag=true
				break
			}
		}
		if flag==true{
			index++
			continue
		}else{
			return false
		}
	}
	return true
}
func main(){
	s,t:="abc","ahbgdc"
	fmt.Println(isSubsequence(s,t))
}