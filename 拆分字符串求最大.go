package main

import "fmt"

func maxUniqueSplit(s string) int{
	words:=map[string]bool{}
	count:=0
	var dfs func(string)
	dfs=func (s string){
		if len(words)+len(s)<count{
			return
		}
		if len(s)==0{
			count=max(count,len(words))
			return
		}
		for i:=0;i<len(s);i++{
			cur:=s[:i + 1]
			if _,ok:=words[cur];!ok {
				words[cur]=true
				dfs(s[i+1:])
				delete(words,cur)
			}
		}
	}
	dfs(s)
	return count
}

func max(x,y int) int {
	if x>y{
		return x
	}
	return y
}

func main(){
	fmt.Println("拆分字符串求最大个数")
	s:="wwwhhtp"
	fmt.Println(maxUniqueSplit(s))
}


