/*
题目描述：
给你两组点,其中第一组中有size1个点,第二组中有size2个点,且size1>=size2.
任意两点间的连接成本cost由大小为size1 x size2矩阵给出,其中cost[i][j]是
第一组中的点i和第二组中的点j的连接成本.如果两个组中的每个点都与另一组中的一个
或多个点连接,则称这两组点是连通的.换言之,第一组中的每个点必须至少与第二组中的
一个点连接,且第二组中的每个点必须至少与第一组中的一个点连接.返回连通两组点所需的最小成本

 
示例 1：
输入：cost = [[15, 96], [36, 2]]
输出：17
解释：连通两组点的最佳方法是：
1--A
2--B
总成本为:17

示例 2：
输入：cost = [[1, 3, 5], [4, 1, 1], [1, 5, 3]]
输出：4
解释：连通两组点的最佳方法是：
1--A
2--B
2--C
3--A
最小成本为:4
请注意,虽然有多个点连接到第一组中的点2和第二组中的点A,但由于题目并不限制连接点的数目,所以只需要关心最低总成本.

解题思路:
问题等价于:在一个矩阵中选取一些值,满足矩阵的每一行和每一列都至少有一个元素被选中,同时选中元素
的总和最小(此矩阵就是cost矩阵).由于矩阵的列数较少,我们可以用状压DP来表示每一行的选取情况,
,那么我们维护一个DP矩阵dp[m][1<<n],dp[i][j]表示当前选取到第ii行,每列的选取状况为jj时
总的最小开销,其中jj的第kk位为11即表示第kk列已经被选取过了.那么状态转移方程为:
dp[i][j][k]=min(dp[i][j|k],dp[i-1][k]+costMatrix[i][j],
其中,costMatrix[i][j]表示第i行选取状况为j时该行被选取得元素总和.
最终结果为dp[m-1][(1<<n)-1],表示选取到m-1行(即最后一行),并且每一列都有元素被选取到条件
下得元素最小和.每行都有元素要被选取的约束是由三重循环中j和k都由1开始满足的.


*/


package main

import "fmt"

func connectTwGroups(cost [][]int)int{
	m,n:=len(cost),len(cost[0])
	var (
		costMatrix [][]int
		temp []int
		dp [][]int
	)
	for j:=0;j<(1<<n);j++{
		temp=append(temp,0)
	}
	for i:=0;i<m;i++{
		costMatrix=append(costMatrix,temp)
		dp=append(dp,temp)
	}


	for k:=0;k<m;k++{
		for i:=0;i<(1<<n);i++{
			sum:=0
			for j:=0;j<n;j++{
				if i&(1<<j)>0{
					sum+=cost[k][j]
				}
			}
			costMatrix[k][i]=sum
		}
	}
	/*填充最大值*/
	fmt.Println(dp)

	for i:=0;i<m;i++{
		for j:=0;j<(1<<n);j++{
			if i==0{
				fmt.Println(costMatrix[i][j])
				dp[i][j]=costMatrix[i][j]
			}else{
				dp[i][j]=50
			}
		}
	}
	fmt.Println(dp[0])
	for i:=1;i<m;i++ {
		for k:=1;k<(1<<n);k++ {
			/*首先将第i行只选取一个元素的情况都考虑一遍*/
			/*这样做的目的是保证第i行至少选取了一个元素*/
			for j:=0;j<n;j++ {
				dp[i][k|(1<<j)]=Mathmin(dp[i][k|(1<<j)], dp[i-1][k]+cost[i][j])
			}
			/*rest表示截至第i行还没被选过的列*/
			rest:=(1<<n)-1-k
			/*只遍历没选过的列的所有组合*/
			for j:=rest;j>=1;j=rest&(j-1){
				dp[i][j|k]=Mathmin(dp[i][j|k],dp[i-1][k]+costMatrix[i][j])
			}
		}
	}
	return dp[m-1][(1<<n)-1]
}

func Mathmin(a,b int)int{
	if a>=b{
		return b
	}else{
		return a
	}
}
func main(){
	fmt.Println("连通两组点最小的成本")
	cost:=[][]int{{1, 3, 5},{4, 1, 1},{1, 5, 3}}
	fmt.Println(connectTwGroups(cost))
}