package main

import "fmt"

func segitiga(a, b, c int) bool {
	return (a+b > c) && (a+c > b) && (b+c > a)
}

func main() {
	var sisi1, sisi2, sisi3 int
	fmt.Scanf("%d %d %d", &sisi1, &sisi2, &sisi3)
	if segitiga(sisi1, sisi2, sisi3) {
		fmt.Println("segitiga")
	} else {
		fmt.Println("bukan segitiga")
	}
}
