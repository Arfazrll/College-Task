package main

import "fmt"

const NMAX int = 1000

type count [NMAX]int

func main() {
	var x count
	var n int
	fmt.Scan(&n)
	inputCount(&x, &n)
	sortCount(x, n)
}

func inputCount(x *count, n *int) {
	for i := 0; i < *n; i++ {
		fmt.Scan(&x[i])
	}
}
func sortCount(x count, n int) {
	var pass, idx, i, temp int
	pass = 1
	for pass <= n-1 {
		idx = pass - 1
		i = pass
		for i < n {
			if x[idx] > x[i] {
				idx = i
			}
			i = i + 1
		}
		temp = x[pass-1]
		x[pass-1] = x[idx]
		x[idx] = temp
		pass = pass + 1

	}
	var median float64
	for i := 0; i < n; i++ {
		median += float64(x[i])
	}
	median = median / float64(n)
	fmt.Println()
	fmt.Println(median)
}
