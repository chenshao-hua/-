/**
实现默认将所有的连接视为长连接:keep-alive
 */

package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
)

func main(){
	c:=&http.Client{}
	req,err:=http.NewRequest("Get","http://localhost:8080",nil)
	if err!=nil{
		panic(err)
	}
	fmt.Printf("%#v\n",*req)

	for i:=0;i<5;i++{
		resp,err:=c.Do(req)
		if err!=nil{
			fmt.Println("http get error:",err)
			return
		}
		defer resp.Body.Close()

		b,err:=ioutil.ReadAll(resp.Body)
		if err!=nil{
			fmt.Println("read body error:",err)
			return
		}
		fmt.Println("response body:",string(b))
	}
}
