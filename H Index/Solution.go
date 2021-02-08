
package main

import (
	"fmt"
	"sort"
)

func hIndex(citations []int) int {
	//sort.Slice(citations, func(i, j int)bool{
	//	return citations[i]>citations[j]
	//})//降序排列
	sort.Sort(sort.Reverse(sort.IntSlice(citations)))//降序排序
	h:=0
	for i:=1;i<len(citations);i++{
		if citations[i]>=(i+1){
			h=i+1
		}
	}
	fmt.Println(citations)
	return h
}

func hIndexOne(citations []int)int{
	//归并排序,从小到大
	quicksort(citations,0,len(citations)-1)
	h:=0
	for i:=len(citations)-1;i>=0;i--{
		if citations[i]>=len(citations)-i{
			h++
		}else{
			break
		}
	}
	return h
}

func quicksort(a []int,lo,hi int){
	if lo>=hi{
		return
	}
	p:=partitionSort(a,lo,hi)
	quicksort(a,lo,p-1)
	quicksort(a,p+1,hi)
}

func partitionSort(a []int,lo,hi int)int{
	pivot:=a[hi]
	i:=lo-1
	for j:=lo;j<hi;j++{
		if a[j]<pivot{
			i++
			a[j],a[i]=a[i],a[j]
		}
	}
	a[i+1],a[hi]=a[hi],a[i+1]
	return i+1
}

func hIndexTwo(citations []int)int{
	n:=len(citations)
	buckets:=make([]int,n+1)
	for _,c:=range citations{
		if c>=n{
			buckets[n]++
		}else{
			buckets[c]++
		}
	}
	count:=0
	for i:=n;i>=0;i--{
		count+=buckets[i]
		if count>=i{
			return i
		}
	}
	return 0
}
func main(){
	citations:=[]int{3,0,6,4,4,3,1,5}
	fmt.Println(hIndex(citations))
	fmt.Println(hIndexOne(citations))
	fmt.Println(hIndexTwo(citations))
}
