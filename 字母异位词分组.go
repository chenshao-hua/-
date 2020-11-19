/*
题目描述：
给定一个字符串数组，将字母异位词组合在一起.字母异位词指字母相同，但排列不同的字符串.

示例 1：
Input:["eat", "tea", "tan", "ate", "nat", "bat"]
Output:[["ate","eat","tea"],["nat","tan"],["bat"]]

所有输入均为小写字母.不考虑答案输出的顺序.

解题思路：
利用哈希表查找,构造一个哈希表,一个比较简单的思路是用26个字母的ASCII值,把字符串的各个字母,
这样可保证字母异位词的乘积必定相等的.则可以通过比较乘积判断字符串是否相同.
*/

package main

import "fmt"

func groupAnagrams(letters []string)(list [][]string){
	dictionary:=map[byte]int{'a':2,'b':3,'c':5,'d':7,'e':11,'f':13,'g':17,'h':19,
		'i':23,'j':29,'k':31,'l':37,'m':41,'n':43,'0':47,'p':53,'q':59,'r':61,'s':67,'t':71,
	     'u':73,'v':79,'w':83,'x':89,'y':97,'z':101}
	hash:=make(map[int][]string)
	for _,letter:=range letters{
		m:=1
		for i:=0;i<len(letter);i++{
			m*=dictionary[letter[i]]
		}
		if hash[m]==nil{
			hash[m]=[]string{}
		}
		hash[m]=append(hash[m],letter)
	}

	for _,value:=range hash{
		list=append(list,value)
	}
	return
}
func main(){
	fmt.Println("求字母异位词分组")
	letters:=[]string{"eat", "tea", "tan", "ate", "nat", "bat"}
	fmt.Println(groupAnagrams(letters))
}