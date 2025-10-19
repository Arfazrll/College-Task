package main

import "fmt"

func main() {
	var x int
	var y bool

	fmt.Scanln(&x)
	fmt.Scanln(&y)

	if x >= 17 && y {
		fmt.Println("bisa membuat ktp")
	} else {
		fmt.Println("gak bisa bikin ktp")
	}
}
