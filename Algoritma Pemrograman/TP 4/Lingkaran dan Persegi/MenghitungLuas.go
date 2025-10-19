package main

import "fmt"

func LuasKelilingLingkaran(radius float64, luasLingkaran, kelilingLingkaran *float64) {
	const pi float64 = 3.14

	*luasLingkaran = pi * radius * radius
	*kelilingLingkaran = 2 * pi * radius
}

func LuasKelilingPersegi(sisi float64, luasPersegi, kelilingPersegi *float64) {

	*luasPersegi = sisi * sisi
	*kelilingPersegi = 4 * sisi
}

func hitungTotal(luasLingkaran, luasPersegi, kelilingLingkaran, kelilingPersegi float64, toLuas, toKel *float64) {

	*toLuas = luasLingkaran + luasPersegi
	*toKel = kelilingLingkaran + kelilingPersegi
}

func main() {
	var radius, sisi, luasLingkaran, luasPersegi, kelilingLingkaran, kelilingPersegi, toLuas, toKel float64

	fmt.Scan(&radius, &sisi)
	if radius != 0 && sisi != 0 {
		fmt.Printf("%7s %7s %7s %7s %7s %7s %7s %7s\n", "R", "S", "LL", "LP", "KL", "KP", "TL", "TP")
	}
	for radius != 0 && sisi != 0 {

		LuasKelilingLingkaran(radius, &luasLingkaran, &kelilingLingkaran)
		LuasKelilingPersegi(sisi, &luasPersegi, &kelilingPersegi)
		hitungTotal(luasLingkaran, luasPersegi, kelilingLingkaran, kelilingPersegi, &toLuas, &toKel)
		fmt.Printf("%7.2f %7.2f %7.2f %7.2f %7.2f %7.2f %7.2f %7.2f\n", radius, sisi, luasLingkaran, luasPersegi, kelilingLingkaran, kelilingPersegi, toLuas, toKel)
		fmt.Scan(&radius, &sisi)
	}
}
