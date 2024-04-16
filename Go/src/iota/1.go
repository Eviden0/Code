package main

import "fmt"

const (
	man = iota
	women
	middleman
	unbelivalble
)

func main() {
	fmt.Printf("%d %d %d %d", man, women, middleman, unbelivalble)
}
