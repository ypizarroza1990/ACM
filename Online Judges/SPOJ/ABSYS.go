package main

import (
	"fmt"
	"strconv"
	s "strings"
)

func main() {
	var n int;
	var a,b,c string;
	var va,vb,vc int;
	fmt.Scanln(&n);
	for j:=0 ; j<n; j++ {
		fmt.Scanln()
		fmt.Scanf("%s + %s = %s",&a,&b,&c)
		if s.Contains(a, "machula"){
			vc,_ =strconv.Atoi(c);
			vb,_ =strconv.Atoi(b);
			va = vc - vb
		} else if s.Contains(b, "machula"){
			vc,_ =strconv.Atoi(c);
			va,_ =strconv.Atoi(a);
			vb = vc - va
		}else{
			vb,_ =strconv.Atoi(b);
			va,_ =strconv.Atoi(a);
			vc = va + vb
		}
		fmt.Printf("%d + %d = %d\n",va,vb,vc)
	}
}