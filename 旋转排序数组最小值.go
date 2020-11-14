/*
题目描述:
假设按照升序排序的数组在预先未知的某个点上进行了旋转.(例如,数组[0,1,2,4,5,6,7)可能
变成[4,5,6,7,0,1,2]).请找出其中最小的元素,注意数组中可能存在重复的元素.

示例1：
Input:[1,3,5]
Output:1

示例2:
Input:[2,2,2,0,1]
Output:0

解题思路：
二分查找可以高效解决此问题.带有重复数字时，主要问题出现在开头、末尾的数字出现重复.
（1）开头和末尾的数字重复时,在移动最左端L指针时容易跳过最小值,如[2,3,1,2,2,2,2,2,2,2];
（2）在移动最右端R指针时容易跳过最小值,如[2,2,2,2,0,1,2];
解决方法:先去重(开头、末尾的重复数字),若开头等于末尾时,最左端L指针+1,直到两者不等.
*/

package main

import "fmt"

func findMin(nums []int)int{
	L,R:=0,len(nums)-1
	if R==0{
		return nums[R]
	}
	for L<=R&&nums[L]==nums[R]{
		L++
	}
	temp:=L
	if nums[temp]<nums[R]{
		return nums[temp]
	}

	for L<R{
		mid:=(L+R)/2
		if nums[mid]>=nums[temp]{
			L=mid+1
		}else{
			R=mid
		}
	}
	return nums[R]
}
func main(){
	fmt.Println("寻找旋转数组中最小值")
	nums:=[]int{2,3,1,2,2,2,2,2,2,2}
	fmt.Println(findMin(nums))
}

