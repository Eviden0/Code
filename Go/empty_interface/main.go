package main

import "fmt"

func main() {
	// 定义 a 为空接口
	var a interface{}
	i := 5
	s := "Hello"
	// a 可以存储任意类型的数值
	a = i
	a = s
	fmt.Print(a)
}
