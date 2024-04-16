package main

import (
	"fmt"
)

type Rope string

func main() {
	//类型别名得到的新类型并非和原类型完全相同
	// ，新类型不会拥有原类型所附带的方法
	var a, b Rope = "123", "321"
	fmt.Println(a, b)

	//byte 型
	var ch byte = 'A'
	ch += 1
	chyinshi := 'a'
	chyinshi++
	fmt.Println((ch), byte(chyinshi))
	fmt.Printf("%c %c", ch, chyinshi)
}
