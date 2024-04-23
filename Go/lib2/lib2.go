package lib2

import "fmt"

// 可以被调用的方法一定要大写
func AddSum(a, b int) int {
	return a + b
}

func init() {
	fmt.Println("lib2 is used!")
}
