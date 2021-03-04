/**
实现http server端不支持keep-alive,SetKeepAlivesEnabled方法意思就是全局关闭了该server对keep-alive
连接的支持.
 */
package main

import (
	"log"
	"net/http"
)

func IndexNo(w http.ResponseWriter,r *http.Request){
	log.Println("receive a request from:",r.RemoteAddr,r.Header)
	w.Write([]byte("ok"))
}

func main(){
	http.HandleFunc("/",IndexNo)
	var s=http.Server{
		Addr: ":8080",
		Handler: http.HandlerFunc(IndexNo),
	}
	s.SetKeepAlivesEnabled(false)
	s.ListenAndServe()
}