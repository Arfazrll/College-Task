package main

import (
	"fmt"
)

func main() {
	var money int
	var dompet int
	fmt.Scan(&money)
	dompet = 0

	for money != 0 {
		dompet = (dompet + money)
		fmt.Scan(&money)
	}
	fmt.Println(dompet)
}
