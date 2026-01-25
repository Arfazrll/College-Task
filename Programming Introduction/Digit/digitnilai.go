package main

import "fmt"

func main() {
	var x int
	fmt.Scanf("%d", &x)
	if x < 100 || x > 999 {
		return
	}

	d1 := x / 100
	d2 := (x % 100) / 10
	d3 := x % 10

	fmt.Printf("%d %d %d\n", d1, d2, d3)
}
