package main

import "fmt"

func partition(arr *[]int, p, r int) int {
	pivotKey := (*arr)[r]
	i := p - 1
	for j := p; j < r; j++ {
		if (*arr)[j] <= pivotKey {
			i++
			temp := (*arr)[i]
			(*arr)[i] = (*arr)[j]
			(*arr)[j] = temp
		}
	}
	temp := (*arr)[i+1]
	(*arr)[i+1] = (*arr)[r]
	(*arr)[r] = temp
	return i + 1
}

func quickSort(arr *[]int, p, r int) {
	if p < r {
		q := partition(arr, p, r)
		quickSort(arr, p, q-1)
		quickSort(arr, q+1, r)
	}
}

func main() {
	arr := []int{2, 8, 7, 1, 3, 5, 6, 4}
	quickSort(&arr, 0, len(arr)-1)

	fmt.Println(arr)
}
