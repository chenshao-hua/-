package main

import "fmt"

func countSubstring(s string)int{
	/*统计回文子串个数*/
	count:=0
	/*dp切片为len(s)*len(s)个，初始值为false*/
	dp:=make([][]bool,len(s))
	for i:=0;i<len(s);i++{
		dp[i]=make([]bool,len(s))
	}

	for i:=0;i<len(s);i++{
		for j:=0;j<=i;j++{
			if i==j{
				/*当存在一个字符时，自然就是回文子串*/
				dp[j][i]=true
				count++
			}else if i-j==1&&s[j]==s[i]{
				/*当存在两个字符时，若两者相等，自然也是回文子串*/
				dp[j][i]=true
				count++
			}else if i-j>1&&s[j]==s[i]&&dp[j+1][i-1]==true{
				/*三个以及以上字符时*/
				dp[j][i]=true
				count++
			}
		}
	}
	return count
}
func main(){
	fmt.Println("计算字符串回文子串的个数")
	s:="aba"
	fmt.Println(countSubstring(s))
}