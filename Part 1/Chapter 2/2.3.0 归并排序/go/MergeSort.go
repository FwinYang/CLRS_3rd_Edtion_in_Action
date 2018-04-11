package main

import (
	"fmt"
)

func merge(arrL, arrR []int) (result []int) {
	for !(len(arrL) == 0 && len(arrR) == 0) {
		if len(arrL) == 0 || (len(arrR) > 0 && arrL[0] > arrR[0]) {
			result = append(result, arrR[0])
			arrR = arrR[1:len(arrR)]
		} else if len(arrR) == 0 || (len(arrL) > 0 && arrL[0] <= arrR[0]) {
			result = append(result, arrL[0])
			arrL = arrL[1:len(arrL)]
		}
	}

	return
}

func mergeSort(arr []int) []int {
	if len(arr) > 1 {
		var midPos = int(len(arr) / 2)
		var lPartArr = arr[0:midPos]
		var rPartArr = arr[midPos:len(arr)]
		return merge(mergeSort(lPartArr), mergeSort(rPartArr))
	}
	return arr
}

func main() {
	arr := []int{5, 1, 3, 4, 2, 8, 6, 7}

	fmt.Println(mergeSort(arr))
}
