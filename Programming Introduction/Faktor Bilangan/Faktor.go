package main

import "fmt"

func faktor(x, y int) bool {
	if y%x == 0 {
		return true
	} else {
		return false
	}
}

func main() {
	var x, y int
	fmt.Scan(&x, &y)

	if faktor(x, y) {
		fmt.Println(faktor(x, y))
	} else {
		fmt.Println(faktor(x, y))
	}
}
