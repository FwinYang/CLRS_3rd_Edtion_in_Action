package main

import (
	"fmt"
	"math/rand"
	"time"
)

func randomizedPartition(arr *[]int, p, r int) int {
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

func randomizedSelect(arr *[]int, p, r, index int) int {
	if p == r {
		return (*arr)[p]
	} else if p < r {
		q := randomizedPartition(arr, p, r)
		k := q - p + 1
		if index == k {
			return (*arr)[q]
		} else if index < k {
			return randomizedSelect(arr, p, q-1, index)
		} else {
			return randomizedSelect(arr, q+1, r, index-k)
		}
	}
	return 0
}

func main() {
	arr := []int{2, 8, 7, 1, 3, 5, 6, 4}
	fmt.Println(arr)

	fmt.Println("这个数组中第4小的元素为：")
	fmt.Println(randomizedSelect(&arr, 0, len(arr)-1, 4))
}
