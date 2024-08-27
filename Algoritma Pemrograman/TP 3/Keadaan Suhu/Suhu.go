package main

import "fmt"

func fahrenheit(c float64) float64 {
	return (9*c)/5 + 32
}

func reamur(c float64) float64 {
	return (4 * c) / 5
}

func kelvin(c float64) float64 {
	return c + 273.15
}

func main() {
	var i, c1, c2, k int
	var C, R, F, K float64

	fmt.Scan(&c1, &c2, &k)

	fmt.Println("Celcius  Reamur   Fahrenheit   Kelvin")
	for i = c1; i <= c2; i = i + k {
		F = fahrenheit(float64(i))
		R = reamur(float64(i))
		K = kelvin(float64(i))
		C = float64(i)

		fmt.Printf("   %.2f ", C)
		fmt.Printf("    %.2f ", R)
		fmt.Printf("     %.2f ", F)
		fmt.Printf("    %.2f ", K)
		fmt.Println()
	}
}

