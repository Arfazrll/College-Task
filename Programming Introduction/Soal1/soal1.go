package main

import (
	"fmt"
)

func main() {
	var (
		nama, password string
		attempt        int
		check          bool
	)
	attempt = 0
	check = false
	fmt.Scan(&nama, &password)
	if nama == "admin" && password == "admin" {
		check = true
		fmt.Println("berhasil", attempt)
	}
	for !check {
		attempt++
		fmt.Println("salah")
		fmt.Scan(&nama, &password)
		if nama == "admin" && password == "admin" {
			check = true
			fmt.Println(attempt)
			fmt.Println("berhasil")
		}
	}

}
