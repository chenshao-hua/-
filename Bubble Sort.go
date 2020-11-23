package main

import "fmt"

func bubble_sort(nums []int,n int){
	for i:=1;i<n;i++{
		flag:=false
		for j:=1;j<n-i+1;j++{
			if nums[j]<nums[j-1]{
				nums[j],nums[j-1]=nums[j-1],nums[j]
				flag=true
			}
		}
		if !flag{
			break
		}
	}
}

func main(){
	fmt.Println("冒泡排序")
	nums:=[]int{2,7,5,9,3,4,2}
	bubble_sort(nums,len(nums))
	fmt.Println(nums)
}
