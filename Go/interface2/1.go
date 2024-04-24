package main

import "fmt"

// 万能空接口
func myFcun(arg interface{}) {
	fmt.Println("myFunc is called...")
	fmt.Println(arg)
	value, ok := arg.(string)
	if !ok {
		fmt.Println("arg is not string type")
	} else {
		fmt.Println("arg is string ,and its value is : ", value)
		fmt.Printf("value type is %T\n", value)
	}

}

type Book struct {
	author      string
	page        int
	is_borrowed bool
}

func main() {
	book := Book{
		"Edisen",
		500,
		true,
	}
	myFcun(book.author)
	myFcun(book.page)
	myFcun(book.is_borrowed)
}
