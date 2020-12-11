/*
Given a string containing just the characters'(',')','{',
'}','['and']',determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed by in the correct order.
Note that an empty string is also considered valid;

Example 1:
Input:"()"
Output:true

Example 2:
Input:"()[]"
Output:true

Example 3:
Input:"(]"
Output:false

Example 4:
Input:"([)]"
Output:false

解题思路:
这道题是典型的括号问题.可以通过栈的思路解决,遇到左括号就进栈,遇到右
括号就应当与栈顶元素对应的是左括号,然后栈顶元素出栈.最后看栈顶元素
是否还有其他元素,如果为空,即匹配.此外若为空字符也满足括号匹配.
*/
package main

import "fmt"

func IsValid(str string)bool{
	/*空字符串直接返回*/
	if len(str)==0{
		return true
	}
	/*切片可以实现队列和栈*/
	stack:=make([]rune,0)
	for _,v:=range str{
		if (v=='[')||(v=='(')||(v=='{'){
			stack=append(stack,v)
		}else if (v==']'&&len(stack)>0&&stack[len(stack)-1]=='[')||
			(v==')'&&len(stack)>0&&stack[len(stack)-1]=='(')||
			(v=='}'&&len(stack)>0&&stack[len(stack)-1]=='{'){
			stack=stack[:len(stack)-1]
		}else{
			return false
		}
	}
	return len(stack)==0
}
func main(){
	fmt.Println("判断括号是否有效")
	str:="([)]"
	fmt.Println(IsValid(str))
}
