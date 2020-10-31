/*给你两个单词word1和word2，请你计算出将word1换成word2所使用的最小操作数。
你可以对一个单词进行如下三种操作：
1.插入一个字符
2.删除一个字符
3.替换一个字符

示例1：
输入：word1=“horse”，word2=“ros”
输出：3
解释：
horse->rorse(将‘h’替换为‘r’)
rorse->rose(删除‘r’)
rose->ros(‘e’)

式例2：
输入：word1=“intention”，word2=“execution”
输出：5
解释：
intention->inention(删除‘t’)
inention->enention(将‘i’替换为‘e’)
enention->exention(将'n'替换为'x')
exention->exection(将‘n’替换为‘c’)
exction->execution(插入‘u’)
*/

/*编辑距离，是一个典型的动态规划问题。那么，从一个字符串到另外一个字
符串的编辑一定存在？这是必然的，暴力方法可以表明，不必赘述。记dp[i][j]为字
符串A的前i个字符到字符串B的前j个字符的编辑距离，如果A和B为空串，那么i或者j为0，
因此i的区间为[0,lenA]，j的区间为[0,lenB].接下来，我们推导动态规划方程。
(1)如果A[i]等于B[j]，那么此时便是躺赢的模式，即有：
    dp[i][j]=dp[i-1][j-1]
(2)如果A[i]不等于B[j]，则可以进行三种操作（增删改），如下：
   a.把A的前i-1个字符变成B的前j个字符，然后删除一个字符；
   b.把A的前i个字符变成B的前j-1个字符，然后增加一个字符；
   c.把A的前i-1个字符变成B的前j-1个字符，然后改变一个字符；
显然得到动态规划方程为：
   dp[i][j]=1+min{dp[i-1][j],dp[i][j-1],dp[i-1][j-1]}
*/
package main

import (
	"fmt"
)


func MinDistanc(A string,B string)int {
	lenA:=len(A)
	lenB:=len(B)

	//初始化二维slice
	dp:=make([][]int,lenA+1)
	for i:=0;i<lenA+1;i++{
		dp[i]=make([]int,lenB+1)
	}

	for i:=0;i<lenA+1;i++{
		dp[i][0]=i
	}

	for j:=0;j<lenB+1;j++{
		dp[0][j]=j
	}

	for i:=1;i<lenA+1;i++{
		for j:=1;j<lenB+1;j++{
			if A[i-1]==B[j-1]{
				dp[i][j]=dp[i-1][j-1]
			}else{
				dp[i][j]=1+min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])
			}
		}
	}
	return dp[lenA][lenB]
}

func min(x,y,z int)int{
	m:=x
	if x>y{
		m=y
	}
	if m>z{
		m=z
	}
	return m
}

func main(){
	fmt.Println("编辑距离：动态规划")
	fmt.Println("最小操作数为：",MinDistanc("chen","zh"))
}