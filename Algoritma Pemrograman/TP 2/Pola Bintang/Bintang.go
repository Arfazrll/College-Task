package main

import "fmt"

func main() {
	var n int
	fmt.Scanln(&n)

	for i := 0; i < n; i++ {
		for j := 1; j < n; j++ {
			if i >= j {
				fmt.Print("*")
			} else {
				fmt.Print(" ")
			}

			if i < j {
				fmt.Print("*")
			} else {
				fmt.Print(" ")
			}
		}
		fmt.Println()
	}
}