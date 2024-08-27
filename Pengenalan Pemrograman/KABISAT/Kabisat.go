package main

import "fmt"

func main() {
	var x int
	var y bool

	fmt.Scan(&x)

	y = x%400 == 0 || x%4 == 0 && x%100 != 0
	fmt.Println(y)

}
