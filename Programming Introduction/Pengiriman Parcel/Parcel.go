package main

import "fmt"

func main() {
	var x, biaya, biayakirim, totalbiaya, gram int
	fmt.Print("masukan berat parcel (gr) : ")
	fmt.Scan(&x)
	gram = x % 1000
	x = (x - gram) / 1000
	biayakirim = x * 10000
	if x < 10 {
		if gram >= 500 {
			biaya = gram * 5
		} else if gram < 500 {
			biaya = gram * 15
		}
	}
	totalbiaya = biayakirim + biaya
	fmt.Println(x, "kg +", gram, "gr")
	fmt.Println("Rp.", biayakirim, "+", "Rp.", biaya, "=", totalbiaya)
}
