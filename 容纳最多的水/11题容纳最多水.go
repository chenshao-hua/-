package main

import "fmt"

func Min(a ,b int) int{
    if a>b{
    	return b
	}else{
		return a
	}
}

func Max(a ,b int) int{
	if a>b{
		return a
	}else{
		return b
	}
}

func maxArea(nums []int ) int{
	i:=0
	Area:=0
	j:= len(nums)-1
	for{
		temp:=(j-i)*Min(nums[i],nums[j])
		Area=Max(temp,Area)
		if nums[i]>nums[j]{
			j--
		}else{
			i++
		}
		if i>=j{
			break
		}
	}
	return Area
}

func main(){
	fmt.Println("11题：盛最多水的容器")

	nums:=[]int{1,8,6,2,5,4,8,3,7}

	fmt.Println("盛最多水的容器：",maxArea(nums))
}
