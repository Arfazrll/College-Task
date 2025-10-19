package main

import (
	"fmt"
	"math"
)

func panjangX(R, T float64) float64 {
	return R * math.Cos((T*math.Pi)/180)
}

func panjangY(R, T float64) float64 {
	return R * math.Sin((T*math.Pi)/180)
}

func main() {
	var r, t int

	fmt.Scan(&r, &t)

	fmt.Printf("%.2f ", panjangX(float64(r), float64(t)))
	fmt.Printf("%.2f", panjangY(float64(r), float64(t)))
}
