package main

import (
	"fmt"
	"math/rand"
	"time"
)

func partition(arr *[]int, p, r int) int {
	rand.Seed(time.Now().Unix())
	randNum := rand.Intn(r-p) + p
	tempR := (*arr)[randNum]
	(*arr)[randNum] = (*arr)[r]
	(*arr)[r] = tempR

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

func randomQuickSort(arr *[]int, p, r int) {
	if p < r {
		q := partition(arr, p, r)
		randomQuickSort(arr, p, q-1)
		randomQuickSort(arr, q+1, r)
	}
}

func main() {
	arr := []int{2, 8, 7, 1, 3, 5, 6, 4}
	randomQuickSort(&arr, 0, len(arr)-1)

	fmt.Println(arr)
}
