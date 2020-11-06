package main

import "fmt"

type Trie struct {
	next [26]*Trie
	IsEnd bool
}

/*初始化结构体变量*/
func Constructor() Trie{
	return Trie{}
}

/*往结构体中插入单词*/
func (nums *Trie)Insert(word string){
	for _,v:=range word{
		if nums.next[v-'a']==nil{
			nums.next[v-'a']=new(Trie)
			nums=nums.next[v-'a']
		}else{
			nums=nums.next[v-'a']
		}
	}
	nums.IsEnd=true
}

/*查找单词*/
func (nums *Trie)Search(word string)bool{
	for _,v:=range word{
		if nums.next[v-'a']==nil{
			return false
		}
		nums=nums.next[v-'a']
	}
	if nums.IsEnd==false{
		return false
	}
	return true
}

/*查找Trie树中的键前缀*/
func (nums *Trie)StartWith(prefix string)bool{
	for _,v:=range prefix{
		if nums.next[v-'a']==nil{
			return false
		}
		nums=nums.next[v-'a']
	}
	return true
}

func main(){
	fmt.Println("LeetCode：实现前缀树")
	array:=Constructor()
	word:=&array
	word.Insert("hello")
	fmt.Println(word.Search("hello"))
	fmt.Println(word.StartWith("hel"))
}