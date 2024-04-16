// this is about the strings package
// this is show how to use the func
package main

import (
	"fmt"
	"strings"
)

func main() {

	var str string = "This is a example string !"
	var s string = "is"
	fmt.Printf("T/F? Does the sttring \"%s\" have prefix %s?\ts", str, "Th")
	fmt.Printf("%t\n", strings.HasPrefix(str, "Th"))
	fmt.Printf("\n%d", strings.LastIndex(str, s))
	
}
