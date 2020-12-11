/*
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes
of the first two list.

Example 1:
Input:1->2->4,1->3->4
Output:1->1->2->3->4

解题思路:
这道题比较简单,按照题意就可以.可以使用container/list包
*/

package main

import (
	"container/list"
	"fmt"
)

/*
definition for singly-linked list.
*/
type ListNode1 struct{
   val int
   Next *ListNode1
}

func Mergetwolist(l1 *list.List,l2 *list.List)*list.List{
	if l1==nil{
		return l2
	}
	if l2==nil{
		return l1
	}
	ans:=list.New()

	node1,node2:=l1.Front(),l2.Front()
	/*.(int)转换成整形*/
	for node1!=nil&&node2!=nil{
		if node1.Value.(int)>node2.Value.(int){
			ans.PushBack(node2.Value)
			node2=node2.Next()
		}else{
			ans.PushBack(node1.Value)
			node1=node1.Next()
		}
	}
	for ;node1!=nil;node1=node1.Next(){
		ans.PushBack(node1.Value)
	}
	for ;node2!=nil;node2=node2.Next(){
		ans.PushBack(node2.Value)
	}
	return ans
}

func MergeList(l1 *ListNode1,l2 *ListNode1)*ListNode1{
	if l1==nil{
		return l2
	}
	if l2==nil{
		return l1
	}

	if l1.val<l2.val{
		l1.Next=MergeList(l1.Next,l2)
		return l1
	}
	l2.Next=MergeList(l1,l2.Next)
	return l2
}

func main(){
	fmt.Println("合并两个链表")
	/*var 变量名 list.List*/
	fmt.Println("迭代法")
	l1,l2:=list.New(),list.New()
	l1.Init()
	l2.Init()/*清空*/
	l1.PushBack(1)
	l1.PushBack(2)
	l1.PushBack(4)
	l2.PushBack(2)
	l2.PushBack(3)
	l2.PushBack(5)
	ans:= Mergetwolist(l1,l2)
	for p:=ans.Front();p!=nil;p=p.Next(){
		fmt.Printf("%d ",p.Value.(int))
	}
	fmt.Println("\n递归法")
	h1,f1:=new(ListNode1),new(ListNode1)
	h1.val,f1.val=1,2
	h2,f2:=new(ListNode1),new(ListNode1)
	h2.val,f2.val=2,3
	h3,f3:=new(ListNode1),new(ListNode1)
	h3.val,f3.val=4,5
	h1.Next,f1.Next=h2,f2
	h2.Next,f2.Next=h3,f3

	res:=MergeList(h1,f1)
	for p:=res;p!=nil;p=p.Next{
		fmt.Printf("%d ",p.val)
	}
}