/*
题目描述：
给你一个字符串text,该字符串由若干被空格包围的单词组成.每个单词由一个或者多个小
写英文字母组成,并且两个单词之间至少存在一个空格.题目测试用例保证text至少包含一个单词.
请你重新排列空格,使每对相邻单词之间的空格数目都相等,并尽可能最大化该数目.如果不能重新
平均分配所有空格,请将多余的空格放置在字符串末尾,这也意味着返回的字符串应当与原text字符
串的长度相等，返回重新排列空格后的字符串.

示例1：
Input:text = " this is a sentence "
Output:“this is a sentence”
解释：总共有9个空格和4个单词.可以将9个空格平均分配到相邻单词之间,相邻单词间空格数为：9/(4-1)=3个.

示例2：
Input:text = " practice makes perfect"
Output:"practice makes perfect "
解释：总共有7个空格和3个单词.7/(3-1)=3个空格加上1个多余的空格.多余的空格需要放在字符串的末尾.

示例3：
Input:text = “hello world”
Output:“hello world”

示例4：
Input:text = " walks udp package into bar a"
Output:"walks udp package into bar a "

示例 5：
Input:text = “a”
Output:“a”

解题思路：
这道题虽然有点长,但相对容易,先定义一个切片用来存储单词,并统计空格的个数便可以求解.
*/

package main

import "fmt"

func recorderSpace(text string)string{
	words:=make([]string,0)
	count:=0
	word:=""
	for _,cn:=range text{
		if cn==' '{
			count++
			if len(word)>0{
				words=append(words, word)
				word=""
			}
		}else{
			word+=string(cn)
		}
	}
	if len(word)>0{
		words=append(words,word)
	}
	n,p,q:=len(words),0,0
	if n==1{
		p=0
		q=count
	}else{
		p=count/(n-1)
		q=count%(n-1)
	}
	ans:=""
	for i:=0;i<n;i++{
		if i>0{
			for j:=0;j<p;j++{
				ans+=string(' ')
			}
		}
		ans+=words[i]
	}
	for j:=0;j<q;j++{
		ans+=string(' ')
	}
	return ans
}
func main(){
	fmt.Println("重新排列单词之间的空格")
	text:=" walks udp package into bar   a"
	fmt.Printf("\"%s\"\n",recorderSpace(text))
}
