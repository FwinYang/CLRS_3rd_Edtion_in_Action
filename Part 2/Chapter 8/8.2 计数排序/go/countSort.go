package main

import "fmt"

func countSort(arr []int) []int {
	k := 100
	var result []int
	countArr := make([]int, k)
	for _, value := range arr {
		countArr[value]++
	}
	for i := range countArr {
		for j := 0; j < countArr[i]; j++ {
			result = append(result, i)
		}
	}
	return result
}

func main() {
	arr := []int{2, 8, 6, 7, 1, 4, 10, 5, 3, 9, 6, 4, 0, 99}

	fmt.Println("arr:", arr)

	result := countSort(arr)
	fmt.Println("after sort:", result)
}
