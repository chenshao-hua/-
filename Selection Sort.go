package main

import "fmt"

func select_sort(nums []int,n int){
	for i:=0;i<n-1;i++ {
		temp := i
		for j := i + 1; j < n; j++ {
			if nums[j] < nums[temp] {
				temp = j
			}
		}
		nums[temp],nums[i]=nums[i],nums[temp]
	}
}
func main(){
	fmt.Println("选择排序")
	nums:=[]int{6,7,2,3,5,6,9,0}
	select_sort(nums,len(nums))
	fmt.Println(nums)
}
