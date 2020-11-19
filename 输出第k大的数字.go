/*
题目描述：
在一个未排序的数组中，找到第k大的数字.

示例：
Input:[3,2,1,5,6,4],k=2
Output:5

解题思路:
快速选择一般用于求解第k个最大元素的问题，可以在O(n).快速选择的实现与快速排序相似，
不过只需要找到第k个大的枢即可，不需要对其左右在进行排序.
 */

package main

import "fmt"

func findLargest(nums []int,k int)int{
	L,R,target:=0,len(nums)-1,len(nums)-k
	for L<R{
		mid:=quickSelection(nums,L,R)
		if mid==target{
			return nums[mid]
		}
		if mid<target{
			L=mid+1
		}else{
			R=mid-1
		}
	}
	return nums[L]
}
/*快速选择*/
func quickSelection(nums []int,L,R int)int{
	i,j:=L+1,R
	for{
		for i<R&&nums[i]<=nums[L]{
			i++
		}
		for L<j&&nums[j]>=nums[L]{
			j--
		}
		if i>=j{
			break
		}
		nums[i],nums[j]=nums[j],nums[i]
	}
	nums[L],nums[j]=nums[j],nums[L]
	return j
}
func main(){
	fmt.Println("LeetCode-215：在一个无序的数组中，找到第k大的数字")
	nums:=[]int{3,2,1,5,6,4,9}
	fmt.Println(findLargest(nums,2))
}
