package main

import (
	"fmt"
)

func insertSort(arr *[]float32) {
	for j := 1; j < len(*arr); j++ {
		key := (*arr)[j]
		i := j - 1
		for i >= 0 && (*arr)[i] > key {
			(*arr)[i+1] = (*arr)[i]
			i--
		}
		(*arr)[i+1] = key
	}
}

func bucketSort(arr []float32) (result []float32) {
	bucket := make([][]float32, len(arr))
	for _, value := range arr {
		bucket[int(value*10)] = append(bucket[int(value*10)], value)
	}

	for _, value := range bucket {
		if len(value) > 0 {
			insertSort(&value)
		}
	}

	for _, value := range bucket {
		for _, valueInside := range value {
			result = append(result, valueInside)
		}
	}

	return
}

func main() {
	arr := []float32{0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68}

	fmt.Println("arr:", arr)
	arr = bucketSort(arr)

	fmt.Println("after sort:", arr)
}
