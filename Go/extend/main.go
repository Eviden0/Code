package main

import "fmt"

type celsius float64
type report struct {
	sol int
	//组合下面两个结构体,完成所谓继承的概念
	temperature //嵌入
	localtion
}
type temperature struct {
	high, low celsius
}
type localtion struct {
	lat, long float64
}

func (temperature temperature) Ishigh() float64 {
	return float64(temperature.high)
}
func main() {
	bradury := localtion{lat: 38.9, long: -77.0}
	t := temperature{high: 79.2, low: 68.0}
	report := report{
		sol:         15,
		localtion:   bradury,
		temperature: t,
	}
	fmt.Printf("%+v\n", report.temperature.high)
	fmt.Printf("%.2f\n", report.Ishigh())
}
