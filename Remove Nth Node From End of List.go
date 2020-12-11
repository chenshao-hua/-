/*
给定一个链表,删除倒数第n个节点.

Input:1->2->3->4->5,n=2
Output:1->2->3->5

解题思路:
这道题相对比较简单,先循环一次拿到链表的总长度,然后循环到要删除的节点的前一个
节点开始开始删除操作.有一点值得注意的是,删除的节点可能是头节点,要单独处理.

还有一个较为简单的方法,设置两个指针,一个指针距离前一个指针n个距离,同时移动2个指针,
当一个指针移动了终点时,那么前一个指针就是倒数第n个节点了.
*/

package main

import "fmt"

type liNode struct {
	val int
	Next* liNode
}

func removeNthFromEnd(head *liNode,n int)*liNode{
	fmt.Printf("删除倒数第%d个节点\n",n)
	//var fast,slow *liNode
	slow,fast:=head,head
	for i:=0;i<n;i++{
		fast=fast.Next
	}
	/*除的是头节点*/
	if fast==nil{
		head=head.Next
		return head
	}
	for fast.Next!=nil{
		fast=fast.Next
		slow=slow.Next
	}

	slow.Next=slow.Next.Next
	return head
}

func removeNthFromEnd1(head* liNode,n int)*liNode{
	fmt.Printf("删除倒数第%d个节点\n",n)
	if head==nil{
		return nil
	}
	if n<=0{
		return head
	}
	current:=head
	len:=0
	for current!=nil{
		len++
		current=current.Next
	}
	if n>len{
		return head
	}
	if n==len{
		current:=head
		head=head.Next
		current.Next=nil
		return head
	}
	current=head
	i:=0
	for current!=nil{
		if i==len-n-1{
			deleteNode:=current.Next
			current.Next=current.Next.Next
			deleteNode.Next=nil
			break
		}
		i++
		current=current.Next
	}
	return head
}

func main(){
	//head:=new(liNode)
	node1,node2,node3,node4,node5:=new(liNode),new(liNode),new(liNode),new(liNode),new(liNode)
	node1.val,node2.val,node3.val,node4.val,node5.val=1,2,3,4,5
	//head.Next=node1
	node1.Next=node2
	node2.Next=node3
	node3.Next=node4
	node4.Next=node5
	node5.Next=nil
	res:=removeNthFromEnd(node1,4)
	for res!=nil{
		fmt.Println(res.val)
		res=res.Next
	}

}
