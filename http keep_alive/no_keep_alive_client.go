/**
有时候http client在一条连接上的数据请求密度并不高,因此client端并不想长期保持这条连接(占用端口资源),那么client
端可以根据http.Transport实现,该结构体有一个DisableKeepAlives字段,其默认值为false,即启动keep-alive.可以
将其改为true,即关闭keep-alive.
 */

package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"time"
)

func main(){
	tr:=&http.Transport{
		DisableKeepAlives: true,
	}
	c:=&http.Client{
		Transport: tr,
	}
	req,err:=http.NewRequest("Get","http://localhost:8080",nil)
	if err!=nil{
		panic(err)
	}

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
		log.Println("response body:",string(b))
		time.Sleep(4*time.Second)
	}
}
