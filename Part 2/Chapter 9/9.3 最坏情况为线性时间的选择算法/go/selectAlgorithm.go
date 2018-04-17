package main

import (
	"fmt"
	"sort"
)

func selectAlgo(arr *[]int, index int) int {
	subArrays := make([][]int, 0)

	var (
		headPointer   = 0
		behindPointer = 5
	)

	for {
		if behindPointer >= len(*arr) {
			behindPointer = len(*arr)
			tempArr := (*arr)[headPointer:behindPointer]
			sort.Ints(tempArr)
			subArrays = append(subArrays, tempArr)
			break
		}

		tempArr := (*arr)[headPointer:behindPointer]
		subArrays = append(subArrays, tempArr)
		sort.Ints(tempArr)

		headPointer = behindPointer
		behindPointer += 5
	}

	midNums := make([]int, 0)
	for _, value := range subArrays {
		midNums = append(midNums, value[int(len(value)/2)])
	}
	sort.Ints(midNums)

	midNum := midNums[int(len(midNums)/2)]

	leftPartArr := make([]int, 0)
	rightPartArr := make([]int, 0)

	for _, value := range *arr {
		if value < midNum {
			leftPartArr = append(leftPartArr, value)
		} else {
			rightPartArr = append(rightPartArr, value)
		}
	}

	midNumIndex := len(leftPartArr) + 1

	if midNumIndex == index {
		return midNum
	} else if index < midNumIndex {
		return selectAlgo(&leftPartArr, index)
	}
	return selectAlgo(&rightPartArr, index-midNumIndex+1)
}

func main() {
	arr := []int{5, 2, 7, 12, 13, 9, 6, 8, 4, 10, 15, 1, 3, 14, 11, 16}
	fmt.Println(arr)

	result := selectAlgo(&arr, 7)
	fmt.Println("数组中第7小的数是:")
	fmt.Println(result)
}
