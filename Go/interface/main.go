package main

import (
	"fmt"
	"strings"
)

type talker interface {
	talk() string
}

type martian struct {
}

func (m martian) talk() string {
	return "nack nack"
}

type laser int

func (l laser) talk() string {
	return strings.Repeat("pew ", int(l))
}
func shout(t talker) {
	louder := strings.ToUpper(t.talk())
	fmt.Println(louder)
}
func main() {

	// talker = martian{}
	shout(martian{})
	// fmt.Println(talker.talk())
	// talker = laser(3)
	shout(laser(3))
	// fmt.Println(talker.talk())
}
