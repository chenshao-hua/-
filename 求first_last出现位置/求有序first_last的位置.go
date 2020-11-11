package main

import "fmt"

func searchRange(nums []int,target int)(lower,upper int){
	if len(nums)==0{
		lower,upper=-1,-1
		return
	}
	lower=lowerBound(nums,target)
	upper=upperBound(nums,target)-1 /*这里需要减1*/
	/*判断target是否大于数组最大值或者最小值*/
	if lower==len(nums)||nums[lower]!=target{
		lower,upper=-1,-1
		return
	}
	return
}
func lowerBound(nums []int,target int)int{
	L,R,Mid:=0,len(nums),0
	for L<R{
		Mid=(L+R)/2
		if nums[Mid]>=target{
			R=Mid
		}else{
			L=Mid+1
		}
	}
	return L
}

func upperBound(nums []int,target int)int{
	L,R,Mid:=0,len(nums),0
	for L<R{
		Mid=(L+R)/2
		if nums[Mid]>target{
			R=Mid
		}else{
			L=Mid+1
		}
	}
	return L
}
func main(){
	fmt.Println("求增序数组中第一次和最后一次出现的位置")
	nums:=[]int{5,7,7,8,8,10}

	lower,upper:=searchRange(nums,13)
	fmt.Println(lower," ",upper)
}
