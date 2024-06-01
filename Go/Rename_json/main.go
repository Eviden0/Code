package main

import (
	"encoding/json"
	"fmt"
	"os"
)

func exitOnError(err error) {
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}
}
func main() {
	type location struct {
		Lat  float64 `json:"latitude"`
		Long float64 `json:"longtitude"`
	}
	curious := location{
		Lat:  48.858093,
		Long: 2.294350,
	}
	bytes, err := json.Marshal(curious)
	exitOnError(err)
	fmt.Println(string(bytes))
}
