package main

import "fmt"

func distance(a, b location) dis {
	return dis{a.lat + b.lat, a.long + b.long}
}

type location struct {
	lat  float64
	long float64
}
type dis struct {
	lat  float64
	long float64
}

func main() {

	//相当于匿名类,不可复用,只能短暂操作自己
	// var curiosity struct {
	// 	lat  float64
	// 	long float64
	// }
	//区别 var 关键字
	//type 表示类型,可以被复用,相当于面向对象里的'class'

	var spririt location
	spririt.lat = -14.123
	spririt.long = 123213.123
	//初始化2,更推荐
	spririt2 := location{lat: 123.1, long: 123.2}
	fmt.Println(spririt2)
	var opportunity location
	opportunity.lat = 123.123
	opportunity.long = 123.123

	fmt.Printf("%v", distance(spririt, opportunity))
	//带字段名 %+v
	fmt.Printf("%+v", distance(spririt, opportunity))

}
