/**
默认开启keep-alive的http server的实现
 */

package main

import (
	"fmt"
	"net/http"
)

func Index(w http.ResponseWriter,r *http.Request){
	fmt.Println("receive a request from:",r.RemoteAddr,r.Header)
	w.Write([]byte("ok!"))
}

func main(){
	http.HandleFunc("/",Index)
	var s=http.Server{
		Addr: ":8080",
		Handler: http.HandlerFunc(Index),
	}
	s.ListenAndServe()
}
