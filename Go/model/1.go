package main

import "fmt"

type T struct {
	name string
}

func (t T) method1() {
	//值传递,不影响原参数的值
	t.name = "New name 1"
}
func (t *T) method2() {
	//引用传递,传的T类型给*T类型,取出t的地址传进去 method2(&t)
	t.name = "new name 2"
}
func main() {
	t := T{
		"old name",
	}
	fmt.Println("调用前1 name", t.name)
	t.method1()
	fmt.Println("me1调用后", t.name)
	t.method2()
	fmt.Println("me2 掉用后", t.name)
}
