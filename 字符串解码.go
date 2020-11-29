package main

import "fmt"

func decodeString(s string)string{
	res:=""/*结果字符串*/
	multi:=0  /*倍数*/
	smulti,sstring:=make([]int,0),make([]string,0)/*数字栈和字符栈*/
	for _,c:=range s{
		/*逐个字符扫描*/
		if c=='['{
			smulti=append(smulti,multi);
			sstring=append(sstring,res)
			multi=0
			res=""
		}else if c==']'{
			tmp:=""
			curMulti:=smulti[len(smulti)-1]/*取出数字*/
			smulti=smulti[:len(smulti)-1]/*移除最后一个元素*/
			for i:=0;i<curMulti;i++{
				tmp+=res
			}
			res=sstring[len(sstring)-1]+tmp /*构建子串*/
			sstring=sstring[:len(sstring)-1] /*移除最后一个元素*/
		}else if c>='0'&&c<='9'{
			multi=multi*10+int(c)-'0'
		}else{
			res+=string(c)
		}
	}
	return res
}

func main(){
	fmt.Println("实现字符串解码")
	s:="3[a2[c]]"
	fmt.Println(decodeString(s))
}
