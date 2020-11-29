/*
leetCode142
题目描述:给定一个链表,返回链表开始入环的第一个节点.
如果链表无环,则返回null.为了表示给定链表中的环,我们使用整形pos来
表示链表尾连接到链表中的位置(索引从0开始).如果pos是-1,则在该链
表中没有环.注意,pos仅仅是用于标识环的情况,并不会作为参数传递到函数中.
说明:不允许修改给定的链表。

示例 1:
输入:head=[3,2,0,4],pos=1
输出:返回索引为1的链表节点
解释:链表中有一个环,其尾部连接到第二个节点;

示例 2:
输入:head=[1,2],pos=0
输出:返回索引为0的链表节点
解释:链表中有一个环其尾部连接到第一位节点;

示例 3：
输入:head=[1],pos=-1
输出:返回null
解释:链表中没有环;

解题思路:
利用双指针,一个慢指针S、一个快指针F(2S),设置入环前距离为a,慢指针
入环后走过的距离为b,环剩余距离为c,其中b+c代表一个环.
首次相遇：
（1）慢指针走过的路程:S=a+b;
（2）快指针走过的路程:F=a+n(b+c)+b,其中n>=1,快指针起码在环中走
了一圈以上才可能相遇;
（3）快指针走二步,慢指针走一步,即F=2S;
（4）因此2(a+b)=a+n(b+c)+b,所以a=(n-1)(b+c)+c;
（5）其中n为快指针绕的圈数,当n=1,a=c;当n=2,a=一圈+c;当n=3,
a=两圈+c....所以c为入环点,就是所求的索引点;
*/

package main

import "fmt"

//创建节点结构/类型
type Node struct{
	Data interface{}
	Next *Node
}

//创建链表结构
type List struct{
	Head *Node
	Size int   //头节点不作为链表长度
}

//设计接口
type Method interface {
	Insert(i int,v interface{})
	IsNull() bool
	GetSize() int
	Print()
	SetCycle(n int)
	detectCycle() interface{}
}

//创建节点
func CreateNode(v interface{} ) *Node{
	return &Node{v,nil}
}

//创建空链表
func CreateList() *List{
	return &List{CreateNode(nil),0}
}

//基于Method接口实现链表结构体
//在i处插入节点
func (list *List) Insert(i int,v interface{}){
	s:=CreateNode(v)
	pre:=list.Head //头节点
	for count:=0;count<=i;count++{
		if count==i-1{
			s.Next=pre.Next
			pre.Next=s
			list.Size++  //前插法
		}
		pre=pre.Next
	}
}

//判读是否为空
func (list *List) IsNull() bool{
	pre:=list.Head.Next
	if pre==nil{
		return true
	}
	return false
}

//返回链表长度
func (list *List) GetSize() int{
	return list.Size
}

//设计链表打印输出
func (list *List)Print(){
	pre:=list.Head.Next
	fmt.Println("链表：")
	for i:=1;i<=list.Size;i++{
		fmt.Printf("%v -> ", pre.Data)
		pre=pre.Next
	}
}

//设置环入口的索引点
func (list* List)SetCycle(n int){
	temp,last:=list.Head.Next,list.Head.Next
	for i:=1;i<n;i++{
		temp=temp.Next
	}
	for i:=1;i<list.Size;i++{
		last=last.Next
	}
	/*尾部节点指向索引节点*/
	last.Next=temp
}
func (list* List)detectCycle()interface{}{
	fast,slow:=list.Head.Next,list.Head.Next

	/*首次相遇时,slow的位置*/
	for fast!=nil&&fast.Next!=nil{
		fast=fast.Next.Next
		slow=slow.Next
		if slow==fast{
			break
		}
	}

	/*如果快指针走到尽头,没环*/
	for fast==nil||fast.Next==nil{
		return -1
	}

	/*快指针重新出发,相遇位置就是入口的位置*/
	fast=list.Head.Next
	for fast!=slow{
		fast=fast.Next
		slow=slow.Next
	}
	return slow.Data
}

func main() {
	fmt.Println("链表开始入环的第一个节点")
	list := CreateList()
	var m Method //或者var m Method=CreateList()
	m = list
	m.Insert(1, 3)
	m.Insert(2, 7)
	m.Insert(3, 8)
	m.Insert(4, 10)
	m.SetCycle(1)
	m.Print()
	fmt.Println(m.detectCycle())
}