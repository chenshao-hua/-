package main

import (
	"container/list"
	"fmt"
)
/*list列表是任意类型,interface{},不能直接强制转换,但可以
这样:value.(int)*/
func ReveserPrint(head list.List)[]int{
	result:=make([]int,0)
	/*或者result:make([]interface{},0)定义成任意类型的,但返回值必须也是任意类型的*/
	for it:=head.Front();it!=nil;it=it.Next() {
		result = append(result,it.Value.(int))
	}
	return result
}

func main(){
	fmt.Println("从尾部到头打印链表(用数组或切片返回)")
	//head:=list.New()
	var head list.List
	head.Init()/*清空*/
	head.PushBack(1)
	head.PushBack(3)
	head.PushBack(2)
	fmt.Println(ReveserPrint(head))
}
