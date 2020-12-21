/*
Say you have an array for which the (i)th element is the price of
a given stock on day i.Design an algorithm find the maximum profit.
You may complete as many transactions as you like(i.e.,buy one and
sell one share of the stock multiple times).

Note:You may not engage in multiple transactions at the same time(
i.e.,you must sell the stock before you buy again).

Example 1:
Input:[7,1,5,3,6]
Output:7

Explanation:Buy on day 2(price=1) and sell on day 3(price=5),profit=
5-1=4.The buy on day 4(price=3) and sell on day 5(price=6).profit=
6-3=3;

Example 2:
Input:[1,2,3,4,5]
Output:4

Explanation:Buy on day 1(price=1) and sell on day 5(price=5),profit=
5-1=4.Note that you cannot buy on day 1,buy on day 2 and sell them
later,as you are engaging multiple transaction at the same time.You
 must sell before buying again.

题目大意:
给定一个数组,它的第i个元素是一支给定股票第i天的价格.设计一个算法来计算你所能获取的最大
利润.你可以尽可能地完成更多的交易(多次买卖一支股票).注意:你不能同时参与多笔交易(你必须
在每次购买前出售掉之前的股票).

最大收益必然是每次跌入时就买入,涨到顶峰的时候就抛出.只要有涨峰就开始计算赚的钱,连续涨可以用
两两相减进行累加来计算,两两相减2累加,相当于涨到波峰的最大值减去波谷的值.
*/

package main

import "fmt"

func maxProfit(prices []int)int{
	profit:=0
	for i:=1;i<len(prices);i++{
		if prices[i]-prices[i-1]>0{
			profit+=prices[i]-prices[i-1]
		}
	}
	return profit
}
func main(){
	fmt.Println("股票的最大利润")
	prices:=[]int{7,1,5,3,6}
	fmt.Println(maxProfit(prices))
}
