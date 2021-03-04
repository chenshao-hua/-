package main

import "fmt"

func maxProduct(words []string)int{
	if words==nil||len(words)==0{
		return 0
	}
	n,bits,ans:=len(words),make([]int,len(words)),0
	for i:=0;i<n;i++{
		bits[i]=0
		for j:=0;j<len(words[i]);j++{
			bits[i]|=1<<(words[i][j]-'a') //将每个单词转换为二进制
		}
	}
	for i:=0;i<n;i++{
		for j:=i+1;j<n;j++{
			if (bits[i]&bits[j])==0&&(len(words[i])*len(words[j]))>ans{
				ans=len(words[i])*len(words[j])
			}
		}
	}
	return ans
}

func main(){
	words:=[]string{"abcw","baz","foo","bar","xtfn","abcdef"}
	fmt.Println(maxProduct(words))
}
