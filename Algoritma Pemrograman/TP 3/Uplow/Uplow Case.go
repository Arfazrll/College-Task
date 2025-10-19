package main

import "fmt"

func lowToUpper(c rune) rune {
	return c - 32
}

func main() {
	var c rune

	fmt.Scanf("%c", &c)
	fmt.Print(string(lowToUpper(c)))
}
