/*
You have a number of envelops with widths and heights given as a pair of integers(m,h).One
envelope can fit into another if and only if both the width and height of one envelope is
greater than the width and height of the other envelope.
What is the maximum number of envelopes can you Russian doll?(put one inside other)
Note:Rotation is not allowed.

Example:
Input:[[5,4],[6,4],[6,7],[2,3]]
Output:3
Explanation:
The maximum number of envelopes you can Russian doll is 3([2,3]->[5,4]->[6,7])

题目大意:
给定一些标记了宽度和高度的信封,宽度和高度以整数对形式(w,h)出现.当另一个信封的宽度和高度都比这个信封大的时候,
这个信封可以放到另外一个信封里面,如同俄罗斯套娃一样.请计算最多有多少个信封能组成一组"俄罗斯套娃"信封.

解题思路:
排序+二分查找
这道题与第300题有点类似.能组成俄罗斯套娃的条件就是能找到一个最长上升序列.但是这道题是二维的,要求能找到在二维
上都能满足条件的最长上升子序列.先降维,把宽度进行升序排序,然后在高度上寻找最长上升子序列.高度序列的最长严格递
增子序列的长度就是装的最多的信封的个数.
*/
package main

import (
	"fmt"
	"sort"
)

/*自定义排序sort.Sort需要Len(),Less(),Swap()*/
/*
type sortEnvelops [][]int

func (s sortEnvelops) Len() int{
	return len(s)
}
func (s sortEnvelops) Less(i,j int) bool{
	if s[i][0]==s[j][0]{
		return s[i][1]>s[j][1]
	}
	return s[i][0]<s[j][0]
}
func (s sortEnvelops) Swap(i,j int){
	s[i],s[j]=s[i],s[j]
}
*/
func maxEnvelops(envelops [][]int)int{
	/*左边升序,右边降序排序*/
	sort.Slice(envelops, func(i, j int) bool {
		if envelops[i][0]==envelops[j][0]{
			return envelops[i][1]>envelops[j][1]
		}
		return envelops[i][0]<envelops[j][0]
	})
	/*sort.Sort(sortEnvelops(envelops)排序*/
	ans,count:=make([]int,len(envelops)),0
	/*可以省略count、ans,dp:=[]int{}*/
	for _,num:=range envelops{
		low,high:=0,count /*high=len(dp)*/
		for low<high{
			mid:=low+(high-low)>>1
			if num[1]>ans[mid]{/*换成dp[mid]*/
				low=mid+1
			}else {
				high=mid
			}
		}
		/*以下的部分替换成
		if low==len(dp){
		    dp=append(dp,num[1])
		}else{
		    dp[low]=num[1]
		}
		*/
		if low==count{
			count++
		}
		ans[low]=num[1]
	}
	return count
}
func main(){
	envelops:=[][]int{{5,4},{6,4},{6,5},{2,5},{7,6}}
	fmt.Println(maxEnvelops(envelops))
}