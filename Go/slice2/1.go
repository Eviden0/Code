package main

import (
	"fmt"
	_ "fmt"
)

func main() {
	numbers := make([]int, 3, 5) //make一个容量为5但是只初始化3个的动态数组
	numbers2 := make([]int, 3, 5)
	for _, i := range numbers {
		fmt.Println(i)
	}
	fmt.Printf("len = %d, cap = %d , slice = %v\n", len(numbers), cap(numbers), numbers)
	numbers = append(numbers, numbers2...)
	fmt.Println("-------------------")
	for _, i := range numbers {
		fmt.Println(i)
	}
}
