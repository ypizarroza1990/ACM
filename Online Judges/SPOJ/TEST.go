package main

import (
	"fmt"
)

func main() {
	var n int
	for {
		if fmt.Scanln(&n); n == 42 {
			break
		}
		fmt.Println(n)
	}
}