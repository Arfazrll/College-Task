package main

import "fmt"

func konversiWaktu(jam, menit, detik int) int {
	satuanDetik := (jam * 3600) + (menit * 60) + detik
	return satuanDetik
}

func main() {
	var jam, menit, detik, satuanDetik int
	fmt.Scanf("%d %d %d", &jam, &menit, &detik)
	satuanDetik = konversiWaktu(jam, menit, detik)
	fmt.Println("Hasil Konversi:", satuanDetik, "detik") 
}
