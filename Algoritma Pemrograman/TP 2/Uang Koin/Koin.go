package main

import "fmt"

func main() {
	var koin, q, g, n, s, l int
	fmt.Scan(&koin)
	q = koin / 1200
	g = koin % 1200 / 120
	n = koin % 1200 % 120 / 40
	s = koin % 1200 % 120 % 40 / 20
	l = koin % 1200 % 120 % 40 % 20
	fmt.Println(q, g, n, s, l)
}
