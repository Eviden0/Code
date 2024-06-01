package main

import (
	"encoding/json"
	"fmt"
	"os"
)

// create too many struct examples just one time

func exitOnError(err error) {
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}
}
func main() {
	type localtion struct {
		Name string
		Lat  float64
		Long float64
	}
	// 分别对应每一个实例的lat 和 long 字段值
	// lats := []float64{-4.321, 123.23, 1234.22}
	// longs := []float64{123.23, 1234.22, 123.23}
	//结构体数组
	locations := [5]localtion{
		{"Bondi Beach", -33.923036, 151.259052},
		{"Coogee Beach", -33.925049, 151.259052},
		{"Cronulla Beach", -34.028249, 151.157507},
		{"Manly Beach", -33.80010128657071, 151.28747820854187},
		{"Maroubra Beach", -33.950198, 151.259302},
	}
	// test := localtion{"Bondi Beach", -33.923036, 151.259052111}
	bytes, err := json.Marshal(locations[0])
	exitOnError(err)
	fmt.Println(string(bytes))
	for _, location := range locations {
		fmt.Printf("%+v\n", location)
	}
}
