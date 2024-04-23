package main

import (
	"fmt"
	"src/lib2"
)

func change(p int) {
	p += 10
}
func change2(p *int) {
	*p += 10
}
func main() {
	var a int = 1
	change(a)
	change2(&a)
	fmt.Println(" a = ", a)
	fmt.Println(lib2.LibTestSum(1, 2))
}
