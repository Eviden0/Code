package main

func main() {
	var a int
	var b int32
	a = 15
	// b = a + a // 编译错误
	//显式转换后可以通过
	b = int32(a) + int32(a)
	// 对于常量限制很少
	b = b + 5 // 因为 5 是常量，所以可以通过编译
}
