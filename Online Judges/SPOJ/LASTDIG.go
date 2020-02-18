package main

import (
	"fmt"
) 

func modpow(p int, n int, mod int) int{
	var a int = 1;
	for n > 0 {
		if n % 2 == 1{
			a = (a * p) % mod;
		}
		p = (p * p) % mod;
		n = n >> 1;
	}
	return a;
}

func main() {
    var n,a,b int;
    fmt.Scanln(&n);
    for i := 0; i < n; i++ {
        fmt.Scanln(&a, &b);
        fmt.Printf("%d\n", modpow(a,b,10));
	}
}