package main

import "fmt"
import(
	"math/rand"
	"time"
)

func CreateNum(p *int){
	//设置种子
	rand.Seed(time.Now().UnixNano())

	var num int
	for{
		num=rand.Intn(10000)//四位数
		if num>=1000{
			break
		}
	}
	//fmt.Println("num=",num)
	*p=num
}
func GetNum(s []int,num int){
	s[0]=num/1000      //取千位
	s[1]=num%1000/100  //取百位
	s[2]=num%100/10    //取十位
	s[3]=num%10        //取个位
}
func OnGame(randSlice []int){
	var num int
	keySlice:=make([]int,4)
	for{
		for{
			fmt.Printf("请输入一个四位数：")
			fmt.Scan(&num)

			if 999<num&&num<10000{
				break
			}
			fmt.Println("输入的数不符合要求...")
		}
		//fmt.Println("num=",num)
		GetNum(keySlice,num)
		//fmt.Println("keySlice=",keySlice)
		n:=0
		for i:=0;i<4;i++{
			if keySlice[i]>randSlice[i]{
				fmt.Printf("第%d位大了一点\n",i+1)
			}else if keySlice[i]<randSlice[i]{
				fmt.Printf("第%d位小了一点\n",i+1)
			}else{
				fmt.Printf("第%d位猜对了\n",i+1)
				n++
			}
		}
		if n==4{
			fmt.Println("恭喜您！全部猜对了！")
			break   //跳出最外层循环
		}
	}
}
func main(){
	fmt.Println("******欢迎进入猜数字游戏******")

	var randNum int
	CreateNum(&randNum)

	//fmt.Println("randNum=",randNum)

	randSlice:=make([]int,4) //保留四位数字的每一位
	GetNum(randSlice,randNum) //切片是引用传递
	//fmt.Println("randSlice=",randSlice)
	OnGame(randSlice)

}
