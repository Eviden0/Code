package main

import (
	"fmt"
)

// 定长类型
func printArr(a [4]int) {
	a[0] = 100 //引用赋值,此处和c语言里面的数组一样传的其实是地址的指针
	fmt.Printf("The arr type is %T\n", a)
	for i, v := range a {
		fmt.Println("Index is : ", i, "value is : ", v)
	}
	fmt.Print("------------------------------\n")

}

func printArr2(a []int) {
	a[0] = 100
	fmt.Printf("The arr type is %T\n", a)
	for i, v := range a {
		fmt.Println("Index is : ", i, "value is : ", v)
	}
	fmt.Print("------------------------------\n")

}
func main() {
	//定义定长数组
	var myArray1 [10]int //定长数组 与 [4]int 类型不一致
	myArr2 := [4]int{1, 2, 3, 4}
	myArr3 := [3]int{1, 2, 3}
	printArr(myArr2) //直接调用,但是此函数不能调用 myArr1
	//利用:= 定义make推导出slice数组
	slice1 := make([]int, 3)
	// slice1[4] = 1 //越界,无法通过编译
	fmt.Printf("%T\n", slice1)

	for i := 0; i < 10; i++ {
		myArray1[i] = i*10 + 1

	}
	printArr2(myArray1[:])
	printArr2(myArr2[:])
	printArr2(myArr3[:])
	// for i, v := range myArray1 {
	// 	fmt.Println("Index is : ", i, "value is : ", v)
	// }
}
