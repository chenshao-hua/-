/*
Given a non-empty array of integers,every element appears twice except for one.Find that
single one.
Note:
Your algorithm should have a linear runtime complexity.Could you implement it without using
extra memory?

Example 1:
Input:[2,2,1]
Output:1

Example 2:
Input:[4,1,2,1,2]
Output:4

题目大意:
给定一个非空数组,除了某个元素只出现一次之外,其余的每个元素均出现两次.找出只出现一个元素的那个,
要求算法时间复杂度是线性的,并且不使用额外的辅助空间.

方法1:
可以对数组进行排序,然后每次取两个值进行判断,若不等则跳出循环,且前一个值为目标对象;

方法2:
该题目强调有一个数字只出现一次?其他的出现两次?这样容易想到异或运算的性质:任何一个数字异或它
自己都等于0,而且0与任何的数字进行异或等于它本身.也就是说,如果我们从头到尾依次异或数组中的每
一个数字,那么最终结果刚好是那个只出现一次的数字,因为那些出现两次的数字全部在异或运算过程中抵消了.

*/
package main

import (
	"fmt"
	"sort"
)

func singleNumber1(nums []int)int{
	sort.Ints(nums)
	if len(nums)==1{
		return nums[0]
	}
	i:=1
	for ;i<len(nums);i+=2{
		if nums[i-1]!=nums[i]{
			break
		}
	}
	return nums[i-1]
}

func singleNumber2(nums []int)int{
	ans:=0
	for i:=0;i<len(nums);i++{
		ans^=nums[i]
	}
	return ans;
}
func main(){
	fmt.Println("找出只出现一次的元素")
	nums:=[]int{2,2,1}
	fmt.Println(singleNumber2(nums))
}