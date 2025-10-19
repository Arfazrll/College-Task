package main

import "fmt"

func main() {
	var fpb, x, num1, num2 int
	fmt.Scan(&num1, &num2)
	if num1 > num2 {
		x = num2
	} else {
		x = num1
	}
	for i := 1; i <= x; i++ {
		if num1%i == 0 && num2%i == 0 {
			fpb = i
		}
	}
	fmt.Print(fpb)
}
