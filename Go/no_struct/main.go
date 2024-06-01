package main

import "fmt"

type coordinate struct {
	d, m, s float64
	h       rune
}

// converts a d/m/s coordinate to decimal degrees.
func (c coordinate) decimal() float64 {
	sign := 1.0
	switch c.h {
	case 'S', 'W', 's', 'w':
		sign = -1
	}
	return sign * (c.d + c.m/60 + c.s/3600)
}

// construct function
func newCoordinate(d, m, s float64, h rune) coordinate {
	return coordinate{d, m, s, h}
}
func main() {
	lat := coordinate{d: 52, m: 23, s: 34, h: 'N'}
	long := coordinate{d: 13, m: 21, s: 34, h: 'E'}
	curiosite := newCoordinate(52, 23, 34, 'N')
	fmt.Println(lat.decimal(), long.decimal())
	fmt.Print(curiosite.decimal())
}
