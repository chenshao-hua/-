/**
很显然,前面的server处理方式太过霸道,对应理想复用连接,提高请求和应答传输效率的client而言,"一刀切"的机制不是很
合理,可以通过http.Server实例时显示为其字段IdleTimeout做一个显式赋值,例如设置idle超时时间为5s.这样可以让
server既可以对高密度传输数据的连接保持keep-alive,又可以及时清除掉那么长时间没有数据传输的idle连接,释放占用
的系统资源.
 */
package main

import (
	"log"
	"net/http"
	"time"
)

func Index(w http.ResponseWriter,r *http.Request){
	log.Println("receive a request from:",r.RemoteAddr,r.Header)
	w.Write([]byte("ok"))
}

func main(){
	http.HandleFunc("/",Index)
	var s=http.Server{
		Addr: ":8080",
		Handler: http.HandlerFunc(Index),
		IdleTimeout: 5*time.Second,
	}
	s.ListenAndServe()
}

