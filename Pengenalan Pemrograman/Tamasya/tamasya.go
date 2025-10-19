package main

import "fmt"

func main() {
	var n, mobil int
	fmt.Scan(&n)

	mobil = n / 7
	if n%7 != 0 {
		mobil = mobil + 1
	}
	fmt.Println(mobil)
}
