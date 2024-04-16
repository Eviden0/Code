package main

import "fmt"

func change_value_from_value(a int) {
	a = a + 10
}

func change_value_from_address(a *int) {
	*a = *a + 10
}
func main() {
	var a int = 1
	change_value_from_value(a)
	fmt.Println(a)                //此时只是值传递,并不会修改a地址处的值
	change_value_from_address(&a) //引用类型修改,直接修改a地址处指向的值
	fmt.Println("----------------")
	fmt.Println(a)
}
