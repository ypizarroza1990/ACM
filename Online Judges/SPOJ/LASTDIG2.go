package main
import (
	"fmt"
    "math/big"
) 
func main() {
    var n int
    var _a,_b string;
    fmt.Scanln(&n);
    for i := 0; i < n; i++ {
        fmt.Scanln(&_a, &_b);
        var a,_ = new(big.Int).SetString(_a, 10);
        var b, _ = new(big.Int).SetString(_b, 10);
        var ans = new(big.Int)
        ans.Exp(a,b, big.NewInt(10))
        fmt.Printf("%v\n",ans);
    }
}