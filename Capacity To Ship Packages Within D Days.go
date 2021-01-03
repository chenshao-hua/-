/*
A conveyor belt packages that must be shipped from one port to another within D days.
The i-th package on the conveyor belt has a weight of weight[i].Each day,we load the
ship with packages on the conveyor belt(in the order given by weights).We may not load
more weight than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on
the conveyor belt being shipped within D days.

Example 1:
Input:weights=[1,2,3,4,5,6,7,8,9,10],D=5
Output:15
Explanation:
A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day:1,2,3,4,5
2nd day:6,7
3rd day:8
4th day:9
5th day:10
Note that the cargo must be shipped in the order given,so using a ship of capacity
14 and splitting the packages into parts like(2,3,4,5),(1,6,7),(8),(9),(10)is not
all allowed.

题目大意:
传送带上的包裹必须在D天内从一个港口运行到另外一个港口.传送带上的第i个包裹的重量为weights[i].每一天,我们都
会按给出重量的顺序往传送带上装载包裹.可以装载的重量不会超过船的最大运载重量.装载的重量必须是连续的.求返回能
在D天内传送带上的所有包裹送达的船的最低运载能力.

解题思路:
这道题可以使用动态规划DP完成,也可以使用二分搜索完成.这是一道二分搜索里面的max-min最大最小值的问题.题目可以转换
为在D次划分中,求一个x,使得x满足:对任意的S(i),都能S(i)<=x.这个条件保证了x是所有S(i)中的最大值.要求是满足该条件
的最小x.x的搜索范围在[max,min]中.逐步二分逼近low值,直到找到能满足条件的low的最小值,即为最终答案.
*/

package main

import "fmt"

func shipwithinDays(weights []int,D int)int{
	maxnum,sum:=0,0
	for _,num:=range weights{
		sum+=num
		if num>maxnum{
			maxnum=num
		}
	}
	if D==1{
		return sum
	}
	low,high,mid:=maxnum,sum,0
	for low<high{
		mid=low+(high-low)>>1
		if calSum(mid,D,weights){
			high=mid
		}else{
			low=mid+1
		}
	}
	return low
}

func calSum(mid,D int,weights []int)bool{
	sum,count:=0,0
	for _,v:=range weights{
		sum+=v
		if sum>mid{
			sum=v
			count++
			if count>D-1{/*拆分成D块,只需要插桩D-1个*/
				return false
			}
		}
	}
	return true
}
func main(){
	weights,D:=[]int{1,2,3,4,5,6,7,8,9,10},5
	fmt.Println(shipwithinDays(weights,D))
}