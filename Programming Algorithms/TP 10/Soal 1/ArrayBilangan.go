package main

import "fmt"

// Deklarsi konstanta 20 elemen
const NMAX int = 20

// Deklarasi tabInt dengan total NMAX elemen
type tabInt [NMAX]int

func main() {
	// Deklarasi variabel bertipe tabInt
	var array tabInt
	// Deklarasi banyak elemen array
	var n int
	// Pembacaan data bilangan
	baca(&array, &n)
	// Cetak elemen array
	cetakElemen(array, n)
	// Cetak Info
	cetakInfo(array, n)
}

func baca(A *tabInt, n *int) {
	/*
		IS: Array A dengan banyak elemen n terdefinisi sembarang
		Proses: Membaca bilangan bulat dan memasukkan bilangan bulat positif
		        ke dalam array A.Pembacaan dilakukan selama terbaca
		        bilangan positif dan n < NMAX.
		FS: Array A sebanyak n elemen berisi nilai
	*/
	var baca int
	for {
		fmt.Scan(&baca)
		if baca < 1 || *n == NMAX {
			break
		}
		A[*n] = baca
		*n++
	}

}

func cetakElemen(A tabInt, n int) {
	/*
		IS: Array A dengan banyak elemen n terdefinisi
		FS: Tercetak di layar elemen array A sebanyak n dengan format:
			"Elemen array: <e1> <e2> <e3> ... <en>"
	*/
	fmt.Print("Elemen array: ")
	for i := 0; i < n; i++ {

		fmt.Print(A[i], " ")
	}
	fmt.Println()
}

func maksimum(A tabInt, n int) int {
	/* Mengembalikan nilai elemen maksimum dari array A dengan banyak elemen n */
	var maksimumSemenstara int
	maksimumSemenstara = A[0]
	for i := 0; i < n; i++ {
		if A[i] > maksimumSemenstara {
			maksimumSemenstara = A[i]
		}
	}
	return maksimumSemenstara
}

func minimum(A tabInt, n int) int {
	/* Mengembalikan nilai elemen minimum dari array A dengan banyak elemen n */
	var minimumSemenstara int
	minimumSemenstara = A[0]
	for i := 0; i < n; i++ {
		if A[i] < minimumSemenstara {
			minimumSemenstara = A[i]
		}
	}
	return minimumSemenstara
}

func cetakInfo(A tabInt, n int) {
	/*
		IS: Array A dengan banyak elemen n terdefinisi
		FS: Nilai maksimum, nilai minimum, dan banyaknya elemen tercetak dengan format:
			"Nilai maksimum: <max_value>
			 Nilai minimum: <min_value>
			 Banyak elemen: <n>"
	*/
	fmt.Println("Nilai maksimum:", maksimum(A, n))
	fmt.Println("Nilai minimum:", minimum(A, n))
	fmt.Println("Banyak elemen:", n)
}