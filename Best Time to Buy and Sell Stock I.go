/*
Say you have an array for which the i(th) element is the price of a given stock
on day i.
If you were only permitted to complete at most one transaction(i.e,buy one and
sell one share of the stock),design an algorithm to find the maximum profit.
Note that you cannot sell a stock before you buy one.

Example 1:
Input:[7,1,5,3,6,4]
Output:5
Explanation:Buy on day 2(price=1) and sell on day 5(price=6),profit=6-1=5.
Note 7-1=6,as selling price needs to be larger than buying price.

Example 2:
Input:[7,6,4,3,1]
Output:0
Explanation:In this case,no transaction is done,i.e. max profit=0.
解题思路:
方法1:
逐个遍历当前值与后面最大值的差,记录最大的差,时间复杂度O(n^2)
方法2:
只需要遍历数组一遍即可,用一个变量存储遍历过最小的值,并且计算当前值与最小值之间的差值,然后更新
差值.
*/
package main

import "fmt"
/*
func GetMaxProfit(prices []int)int{
	maxprice:=0
	for i:=0;i<len(prices);i++{
		profit:=max1(i+1,prices)
		if profit-prices[i]>maxprice{
			maxprice=profit-prices[i]
		}
	}
	return maxprice
}
func max1(j int,prices []int)int{
	price:=0
	for i:=j;i<len(prices);i++{
		price=maxStock(price,prices[i])
	}
	return price
}
func maxStock(x,y int)int{
	if x>y{
		return x
	}
	return y
}
 */
func GetMaxProfit(prices []int)int{
	res,buy:=0,int(^uint(0)>>1)
	for _,price:=range prices{
		buy=min1(buy,price)
		res=max1(res,price-buy)
	}
	return res
}
func min1(x,y int)int{
	if x>y{
		return y
	}
	return x
}

func max1(x,y int)int{
	if x>y{
		return x
	}
	return y
}

/*单调递减栈*/
func GetMaxProfit1(prices []int)int{
	if len(prices)==0{
		return 0
	}
	stack,res:=[]int{prices[0]},0
	for i:=1;i<len(prices);i++{
		if prices[i]>stack[len(stack)-1]{
			stack=append(stack,prices[i])
		}else{
			index:=len(stack)-1
			for ;index>=0;index--{
				if stack[index]<prices[i] {
					break
				}
			}
			stack=stack[:index+1]
			stack=append(stack,prices[i])
		}
		res=max1(res,stack[len(stack)-1]-stack[0])
	}
	return res
}
func main(){
	fmt.Println("求出售股票的最佳时间")
	prices:=[]int{7,6,4,3,9}
	fmt.Println(GetMaxProfit(prices))
}