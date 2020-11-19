package main

import "fmt"

func quicksort(nums []int,l int,r int){
	if l+1>r{
		return
	}
	first,last:=l,r
	key:=nums[first]
	for first<last{
		for first<last&&nums[last]>=key{
			last--
		}
		nums[first]=nums[last]
		for first<last&&nums[first]<=key{
			first++
		}
		nums[last]=nums[first]
	}
	nums[first]=key
	quicksort(nums,l,last-1)
	quicksort(nums,first+1,r)
}
func main(){
	fmt.Println("快速排序")
	nums:=[]int{1,8,2,5,4,2,3,9,5}
	quicksort(nums,0,len(nums)-1)
	for _,num:=range nums{
		fmt.Printf("%d ",num)
	}
}
