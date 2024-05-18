package main

import (
	"fmt"
)

func main() {
	fmt.Print("Hello, World!")
	// 定义一个数组
	var arr [5]int
	var st string = "hello"
	fmt.Print(st)
	for i := 0; i < 5; i++ {
		arr[i] = i
	}

	for _, i := range arr {
		fmt.Print(i)
	}
	//利用迭代器访问数组
	// for _, value := range arr {
	// 	fmt.Print(value)
	// }

}
