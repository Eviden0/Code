//echo1 prints its command-line arguments.

package main

import (
	"fmt"
	"os"
)

/*
自增语句i++给i加1；这和i += 1以及i = i + 1都是等价的。
对应的还有i--给i减1。
它们是语句，而不像C系的其它语言那样是表达式。
所以j = i++非法，而且++和--都只能放在变量名后面，
因此--i也非法。
*/
// func main() {
// 	var s, sep string
// 	for i := 1; i < len(os.Args); i++ {
// 		s += sep + os.Args[i]
// 		sep = " "
// 	}
// 	fmt.Println(s)
// }
func main() {
	s, sep := "", ""
	// index := 0
	for index, args := range os.Args[1:] {
		s += sep + args + " " + fmt.Sprint(index)
		sep = " "
	}
	// fmt.Println(index)
	fmt.Println(s + " ")
}

// exe 1:
// func main() {
// 	fmt.Println(os.Args[0])
// }
