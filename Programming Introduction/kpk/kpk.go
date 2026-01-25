package main

import "fmt"

func main() {
	var kpk, n, m int
	fmt.Scan(&n, &m)
	for i := 1; kpk == 0; i++ {
		fmt.Print(kpk)
		if i%n == 0 && i%m == 0 {
			kpk = i
		}
	}
	fmt.Print(kpk)
}
