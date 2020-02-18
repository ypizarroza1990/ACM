package main

import (
	"fmt"
    "math/big"
) 


func main() {
	var n int;
    var x int64;
    var ans string;
    fmt.Scanln(&n);
    for i := 0; i < n; i++ {
        fmt.Scanln(&x);
        prime := big.NewInt(x).ProbablyPrime(10);
        if prime{
            ans = "YES";
        }else{
          ans = "NO";
        }
        fmt.Printf("%s\n", ans);
    }
}