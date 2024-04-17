package lib1

import "fmt"

func LibTestSum(a, b int) int {
	return a + b
}
func init() {
	fmt.Println("lib1 is used!")
}
