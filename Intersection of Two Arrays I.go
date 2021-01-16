/*
Given two arrays,write a function to compute their intersection.
Example 1:
Input:nums1=[1,2,2,1],nums2=[2,2]
Output:[2]

Example 2:
Input:nums1=[4,9,5],nums2=[9,4,9,8,4]
Output:[9,4]
解题思路:
利用map即可
*/
package main

import "fmt"

func intersection(nums1,nums2 []int)[]int{
	ans:=[]int{}
	board:=map[int]bool{}
	for _,num:=range nums1{
		board[num]=true
	}
	for _,num:=range nums2{
		if board[num]{
			ans=append(ans,num)
			delete(board,num)
		}
	}
	return ans
}
func main(){
	nums1,nums2:=[]int{1,2,2,1},[]int{2,2}
	fmt.Println(intersection(nums1,nums2))
}
