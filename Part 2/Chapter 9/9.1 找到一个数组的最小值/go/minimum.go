package main

import (
	"fmt"
)

func minimum(arr []int) int {
	miniNum := arr[0] + 1
	for _, value := range arr {
		if value < miniNum {
			miniNum = value
		}
	}
	return miniNum
}

func main() {
	arr := []int{8, 6, 7, 1, 4, 10, 5, 3, 9, 6, 4, 0, 99}

	fmt.Println("arr:", arr)

	fmt.Println("minimum:", minimum(arr))
}
