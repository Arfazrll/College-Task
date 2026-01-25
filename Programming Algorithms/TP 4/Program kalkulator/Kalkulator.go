package main

import "fmt"

func menu() {
	fmt.Println("-----------------------\n        M E N U\n-----------------------\n1. Hitung Penjumlahan\n2. Hitung Perkalian\n3. Hitung Pembagian\n4. Exit\n-----------------------")

}

func hitungJumlah() {
	var x, y float64
	fmt.Print("Masukan dua bilangan yang akan dijumlahkan: ")
	fmt.Scan(&x, &y)
	fmt.Println("Hasil penjumlahan: ", x+y)
}

func hitungPerkalian() {
	var x, y float64
	fmt.Print("Masukan dua bilangan yang akan dikalikan: ")
	fmt.Scan(&x, &y)
	fmt.Println("Hasil perkalian: ", x*y)
}

func hitungPembagian() {
	var x, y float64
	fmt.Print("Masukan dua bilangan yang akan dibagikan: ")
	fmt.Scan(&x, &y)
	fmt.Println("Hasil penjumlahan: ", x/y)

}

func main() {
	var pilih int

	for {
		menu()
		fmt.Print("Pilih (1/2/3/4)? ")
		fmt.Scan(&pilih)

		switch pilih {
		case 1:
			hitungJumlah()
		case 2:
			hitungPerkalian()
		case 3:
			hitungPembagian()
		}

		if pilih == 4 {
			break
		}
	}

}
