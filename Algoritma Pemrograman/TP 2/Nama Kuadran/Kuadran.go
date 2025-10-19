package main

import "fmt"

func main() {
	var x, y float32
	fmt.Scan(&x, &y)
	if x >= 0 {
		if y >= 0 {
			fmt.Print("Kuadran I")
		} else {
			fmt.Print("Kuadran IV")
		}
	} else {
		if y >= 0 {
			fmt.Print("Kuadran II")
		} else {
			fmt.Print("Kuadran III")
		}
	}
}
