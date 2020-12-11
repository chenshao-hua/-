/*
Given n pairs of parentheses,write a function to generate
are all combinations of well-formed parentheses.

Example 1:
Input:n=3
Output:
["((()))","(()())","(())()","()(())","()()()"]

解题思路:
这道题利用深度优先搜索即可,不需要判断括号是否匹配.只需要保证左括号的个数不能小于
右括号的.
*/

package main

import "fmt"

func GenrateParenthese(n int)[]string{
	if n==0{
		return []string{}
	}
	ans:=[]string{}
	findgenerateparenthese(n,n,"",&ans)
	return ans
}

func findgenerateparenthese(lp,rp int,str string,ans *[]string){
	/*剪枝*/
	if lp>rp{
		return
	}
	if lp==0&&rp==0{
		*ans=append(*ans,str)
	}
	if lp>0{
		findgenerateparenthese(lp-1,rp,str+"(",ans)
	}
	if rp>0{
		findgenerateparenthese(lp,rp-1,str+")",ans)
	}
}
func main(){
	fmt.Println("生成括号的组合")
	fmt.Println(GenrateParenthese(3))
}
