package main

import "fmt"

func sum_a_b(a, b int) (r1, r2 int) {
	r1 = a + b
	r2 = (a + b) + 1
	return
}
func main() {
	a, b := 1, 2
	fmt.Println(sum_a_b(a, b))

}
