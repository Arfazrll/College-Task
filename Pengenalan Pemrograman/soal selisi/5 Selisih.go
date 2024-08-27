package main

import "fmt"

func main() {
	var bilangan, selisih, selisih2 int
	var checker bool
	// menulis bilangan
	fmt.Scan(&bilangan)
	// menhitung selisih
	selisih = bilangan % 10
	selisih2 = (bilangan % 100) / 10
	//algoritma selisih
	if (selisih+selisih2) == 1 || (selisih-selisih2) == 1 || (selisih2-selisih) == 1 {
		checker = true
	} else {
		checker = false
	}
	// cetak hasil
	fmt.Println(checker)

}
