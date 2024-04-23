package main

import "fmt"

/*
defer 后于 return 执行
可以在函数return 之后 执行一个东西那就是refer
*/
func deferFunc() int {
	fmt.Println("defer func is called")
	return 0
}
func returnFunc() int {
	fmt.Println("return func is called")
	return 0
}
func returnAnddefer() int {
	defer deferFunc()
	return returnFunc()
}
func main() {
	returnAnddefer()
}
