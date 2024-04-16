package main

import "fmt"

func main() {

	var s1 []int
	if s1 == nil {
		fmt.Println("this array is empty")
	} else {
		fmt.Println("this array is not empty")
	}
	s2 := []int{}
	var s3 []int = make([]int, 0)
	fmt.Println(s1, s2, s3)
	var s4 []int = make([]int, 0, 0)
	fmt.Println(s4)
	s5 := []int{1, 2, 3}
	fmt.Println(s5)
	arr := [5]int{1, 2, 3, 4, 5}
	var s6 []int
	s6 = arr[1:4]
	fmt.Println(s6)
}
