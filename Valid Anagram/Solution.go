/**
Given two strings and t,write a function to determine if it is an anagram of s.

Example 1:
Input:s="anagram",t="nagaram"
Output:true

Example 2:
Input:s="rat",t="car"
Output:false

Follow up:
What if the inputs contain unicode characters?How would you adapt your solution to such case?

题目大意:
给出2个字符串s和t,如果t中的字母在s中都存在(同字母异位),输出true,否则输出false.

解题思路:
方法1:
可以利用哈希进行key-value存储,key存储单个字符,value存储字符个数.这道题需要注意字符串相同也属于anagram,比如"car"和它
本身,空字符串也算是.优化可以利用一个map遍历即可.

方法2:
可以用打表的方式做.先把s中的每个字母都存在一个26容量的数组里面,每个下标依次对应26个字母.s中每个字母都对应表中一个字母,每出现
一次就进行+1.然后再扫描字符串t,每出现一次字母就进行-1.最终表中的值肯定为0.

方法3:
对s,t进行排序
 */

package main

import "fmt"

func isAnagramOne(s string,t string)bool{
	if len(s)!=len(t){
		return false
	}
	res,ans:=map[byte]int{},map[byte]int{}//make(map[byte]int)初始化
	for _,c:=range s{
		res[byte(c)]++;
	}
	for _,c:=range t{
		ans[byte(c)]++;
	}
	for k:=range ans{
		if ans[k]!=res[k]{
			return false
		}
	}
	return true
}

func isAnagramTwo(s,t string) bool{
	if len(s)!=len(t){
		return false
	}
	ans:=make(map[byte]int)
	for _,c:=range s{
		ans[byte(c)]++;
	}
	for _,c:=range t{
		if ans[byte(c)]!=0{
			ans[byte(c)]--
		}
	}
	for _,v:=range ans{
		if v!=0{
			return false
		}
	}
	return true
}

func isAnagramThree(s,t string) bool{
	if len(s)!=len(t){
		return false
	}
	alphabet:=make([]int,26)
	sBytes,tBytes:=[]byte(s),[]byte(t)
	for i:=0;i<len(sBytes);i++{
		alphabet[sBytes[i]-'a']++
	}
	for i:=0;i<len(tBytes);i++{
		alphabet[tBytes[i]-'a']--
	}
	for i:=0;i<len(alphabet);i++{
		if alphabet[i]!=0{
			return false
		}
	}
	return true
}

func isAnagramTFour(s,t string) bool{
	if len(s)!=len(t){
		return false
	}
	sBytes,tBytes:=[]byte(s),[]byte(t)
	quickSortByte(sBytes,0,len(sBytes)-1)
	quickSortByte(tBytes,0,len(tBytes)-1)

	for i:=0;i<len(sBytes);i++{
		if sBytes[i]!=tBytes[i]{
			return false
		}
	}
	return true
}

func quickSortByte(a []byte,lo,hi int){
	if lo>=hi{
		return
	}
	k:=partionByte(a,lo,hi)
	quickSortByte(a,lo,k-1)
	quickSortByte(a,k+1,hi)
}

func partionByte(a []byte,lo,hi int)int{
	pivot,i:=a[hi],lo-1
	for j:=lo;j<hi;j++{
		if a[j]>pivot{
			i++
			a[j],a[i]=a[i],a[j]
		}
	}
	a[i+1],a[hi]=a[hi],a[i+1]
	return i+1
}
func main(){
	s,t:="anagram","nagaram"
	fmt.Println(isAnagramOne(s,t))
	fmt.Println(isAnagramTwo(s,t))
	fmt.Println(isAnagramThree(s,t))
	fmt.Println(isAnagramTFour(s,t))
}
