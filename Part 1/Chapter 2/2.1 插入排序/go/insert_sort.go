package main

import "fmt"

func main() {
	arr := []int{5, 2, 8, 3, 1, 7, 6, 4}

	for j := 1; j < len(arr); j++ {
		key := arr[j]
		i := j - 1
		for i >= 0 && arr[i] > key {
			arr[i+1] = arr[i]
			i--
		}
		arr[i+1] = key
	}

	fmt.Println(arr)
}
