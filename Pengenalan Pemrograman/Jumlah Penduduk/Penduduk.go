package main

import "fmt"

func main() {
	var a, b, c, d, e int
	fmt.Scanf("%d %d %d %d %d", &a, &b, &c, &d, &e)
	x := a + b + c - d - e
	fmt.Printf("%d\n", x)
}
