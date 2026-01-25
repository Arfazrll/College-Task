package main

import (
	"fmt"
)

func main() {
	var bilangan int
	var digit int
	var total int
	total = 0
	fmt.Scan(&bilangan)
	for bilangan > 0 {
		digit = bilangan % 10
		total = (total + digit)
		fmt.Printf("%d ", digit)
		bilangan = (bilangan / 10)
	}
	fmt.Println("")
	fmt.Println(total)
}
