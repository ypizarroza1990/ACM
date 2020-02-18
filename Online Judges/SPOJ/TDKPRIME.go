package main

import (
	"fmt"
) 
const MAX = 90000009;
var primes [MAX>>2] int;
var flag [MAX>>6+10]int;

func ifc(x int) int{
	return flag[x>>6]&(1<<uint8((x>>1)&31))
}

func isc(x int){
    flag[x>>6]|=(1<<uint8((x>>1)&31))
}

func criba() {
	for i := 3; i*i < MAX; i+=2 {
		if ifc(i) == 0{
			for j := i*i; j < MAX; j+=i<<1 {
				isc(j)
			}
		}
	}
	k := 0
	primes[k] = 2;k++;
	for i := 3; i < MAX; i+=2 {
		if ifc(i) == 0{
			primes[k] = i;k++;
		}
	}
}

func main() {
	criba();
	var n,x int;
	fmt.Scanln(&n);
	for i := 0; i < n; i++ {
		fmt.Scanln(&x);
		fmt.Printf("%v\n",primes[x-1]);
	}
}