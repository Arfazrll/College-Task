package main

import "fmt"

func main() {
	var n, m int
	fmt.Scanln(&n)
	fmt.Scanln(&m)
	for i := 0; i <= n && i <= m; i++ {
		if i > 0 {
			if n%i == 0 && m%i == 0 {
				fmt.Println(i)
			}
		}
	}
}
