package main

import (
	"fmt"
)

func bubbleSort(arr []int) []int {
	for i := 0; i < len(arr); i++ {
		for j := len(arr) - 1; j > i; j-- {
			if arr[j] < arr[j-1] {
				temp := arr[j]
				arr[j] = arr[j-1]
				arr[j-1] = temp
			}
		}
	}
	return arr
}

func main() {
	arr := []int{5, 1, 3, 0, 4, 9, 2, 8, 6, 7}

	fmt.Println(bubbleSort(arr))
}
