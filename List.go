/****单链表*****/

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
	Delete(i int)
	GetSize() int
	Search(v interface{}) int
	IsNull() bool
	Print()
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

//删除第i个节点
func (list *List) Delete(i int){
	pre:=list.Head //头节点
	for count:=0;count<=i-1;i++{
		s:=pre.Next
		if count==i-1{
			pre.Next=s.Next
			list.Size--
		}
		pre=pre.Next
	}
}

//返回链表长度
func (list *List) GetSize() int{
	return list.Size
}

//查询v所在的位置
func (list *List) Search(v interface{}) int{
	pre:=list.Head.Next
	for i:=1;i<=list.Size;i++{
		if pre.Data==v{
			return i
		}
		pre=pre.Next
	}
	return 0
}

//判读是否为空
func (list *List) IsNull() bool{
	pre:=list.Head.Next
	if pre==nil{
		return true
	}
	return false
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

func main(){
	list:=CreateList()
	fmt.Println("list is null or?: ",list.IsNull())
	var m Method
	m=list
	m.Insert(1,3)
	m.Insert(2,7)
	m.Insert(3,8)
	m.Insert(4,10)

	m.Print()
}