/*
Given two arrays,write a function to compute their intersection.
Example 1:
Input:nums1=[1,2,2,1],nums2=[2,2]
Output:[2,2]

Example 2:
Input:nums1=[4,9,5],nums2=[9,4,9,8,4]
Output:[4,9]

Note:
(1)Each element in the result should appear as many times as it shows in both arrays.
(2)The result can be in any order.
Follow up:
(1)What if the given array is already sorted?How should you optimize your algorithm?
(2)What if num1's size is small compared to num2's size?Which algorithm is better?
(3)What if elements of nums2 are stored on disk,and the memory is limited such that
you cannot load all elements into the memory at once?

题目大意:
要求输出两个数组的交集元素,如果元素出现多次,则需要输出多次.
解题思路:
这道题利用字典可以达到最优解.把其中一组数子放到字典中,另外字典的key是数组中的数字,value是这个数字出现的次
数.在扫描另外一个数组的时候,每取出一个存在的数组,把字典中的value减去1.若value是0代表不存在.
*/

package main

import "fmt"

func intersect(nums1,nums2 []int)[]int{
	ans,board:=[]int{},map[int]int{}
	if len(nums1)==0||len(nums2)==0{
		return ans
	}
	for _,num:=range nums1{
		_,ok:=board[num]
		if ok{
			board[num]++
		}else{
			board[num]=1
		}
	}
	for i:=0;i<len(nums2);i++{
		_,ok:=board[nums2[i]]
		if ok{
			ans=append(ans,nums2[i])
			if board[nums2[i]]!=1{
				board[nums2[i]]--
				continue
			}
			delete(board,nums2[i])
		}
	}
	return ans
}
func intersect1(nums1,nums2 []int)[]int{
	m:=map[int]int{}
	var res []int
	for _,n:=range nums1{
		m[n]++
	}
	for _,n:=range nums2{
		if m[n]>0{
			res=append(res,n)
			m[n]--
		}
	}
	return res
}
func main(){
	nums1,nums2:=[]int{4,9,5},[]int{9,4,9,8,4}
	fmt.Println(intersect(nums1,nums2))
}