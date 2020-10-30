/*
给定具有头节点的非空单链表，返回链表的中间节点。如果有两个中间节点，则返回第二个中间节点。例如：

输入：[1,2,3,4,5]
输出：此列表中的节点3（序列化：[3,4,5]）
返回的节点的值为3.（该节点的判断序列化为[3,4,5]）。
请注意，我们返回了一个ListNode对象ans，这样：
ans.val = 3，ans.next.val = 4，ans.next.next.val = 5，ans.next.next.next = NULL。


输入：[1,2,3,4,5,6]
输出：此列表中的节点4（序列化：[4,5,6]）
由于列表有两个值为3和4的中间节点，我们返回第二个节点。
*/

/*思路：使用快慢指针来解。

此题理解为高中数学中求两辆车相遇问题，一个以正常速度前进的指针，一个以2倍速度前进的快指针，在快指针指
向链表结尾处时，慢指针肯定处在链表的中间位置。

此解法的时间复杂度是O(N)，空间复杂度是O(1)*/

package main

type Object interface {}
type node struct {
	data Object  //定义数据域
	Next *node
}

type ListNode struct{
	head *node
	size int
}
func middleNode(list *ListNode) *node{
	slow,fast:=list.head,list.head //快慢指针，一个一个，一个两个
	for fast!=nil&&fast.Next!=nil{
		slow=slow.Next
		fast=fast.Next.Next
	}
	return slow
}
