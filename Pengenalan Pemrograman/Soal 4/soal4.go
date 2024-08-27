package main

import (
	"fmt"
)

func main() {
	var (
		n, m, x, y int
		cangkir    int
	)
	fmt.Scan(&n, &m, &x, &y)
	if n >= x && m >= y {
		cangkir = n / x
		if (m / y) < cangkir {
			cangkir = (m / y)
		}
	}
	fmt.Print(cangkir)
}
