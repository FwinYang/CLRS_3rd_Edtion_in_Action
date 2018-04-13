package main

import (
	"fmt"
	"math"
)

func getIndexValue(num, index int) int {
	powNum := math.Pow(10, float64(index))
	floorNum := math.Floor(float64(num) / powNum)
	return int(floorNum) % 10
}

func countSort(arr []int, index int) []int {
	var result []int
	m := make(map[int]int)
	for _, value := range arr {
		m[getIndexValue(value, index)] = value
	}
	for i := 0; i < 10; i++ {
		elem, ok := m[i]
		if ok {
			result = append(result, elem)
		}
	}
	return result
}

func radixSort(arr *[]int) {
	for i := 0; i < 3; i++ {
		*arr = countSort(*arr, i)
	}
}

func main() {
	arr := []int{329, 457, 642, 831, 596, 720, 115}

	fmt.Println("arr:", arr)
	radixSort(&arr)

	fmt.Println("after sort:", arr)
}
