package main

import (
	"fmt"
)

func findMaxXingSubArr(arr []int) (int, []int) {
	midIndex := int(len(arr) / 2)
	tempLArr := arr[0:midIndex]
	tempRArr := arr[midIndex:len(arr)]

	var tempMaxLArr, tempMaxRArr []int
	var lMaxSum, rMaxSum = tempLArr[len(tempLArr)-1] - 1, tempRArr[0] - 1
	var lNowSum, rNowSum = 0, 0

	for i := len(tempLArr) - 1; i >= 0; i-- {
		lNowSum += tempLArr[i]
		if lNowSum > lMaxSum {
			lMaxSum = lNowSum
			tempMaxLArr = tempLArr[i:len(tempLArr)]
		}
	}

	for i := 0; i < len(tempRArr); i++ {
		rNowSum += tempRArr[i]
		if rNowSum > rMaxSum {
			rMaxSum = rNowSum
			tempMaxRArr = tempRArr[0 : i+1]
		}
	}

	maxSum := lMaxSum + rMaxSum
	midMaxArr := append(tempMaxLArr, tempMaxRArr...)

	return maxSum, midMaxArr
}

func findMaxSubArr(arr []int) (int, []int) {
	if len(arr) == 1 {
		maxSubArr := arr
		return maxSubArr[0], maxSubArr
	} else {
		midIndex := int(len(arr) / 2)
		tempLArr := arr[0:midIndex]
		tempRArr := arr[midIndex:len(arr)]
		var lMaxSubArray, rMaxSubArray, mMaxSubArray []int
		var lMaxSum, rMaxSum, mMaxSum int
		lMaxSum, lMaxSubArray = findMaxSubArr(tempLArr)
		rMaxSum, rMaxSubArray = findMaxSubArr(tempRArr)
		mMaxSum, mMaxSubArray = findMaxXingSubArr(arr)

		if lMaxSum >= rMaxSum && lMaxSum >= mMaxSum {
			return lMaxSum, lMaxSubArray
		} else if rMaxSum >= lMaxSum && lMaxSum >= mMaxSum {
			return rMaxSum, rMaxSubArray
		}
		return mMaxSum, mMaxSubArray
	}
}

func main() {
	arr := []int{13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7}
	maxSubArr := make([]int, 0)
	var maxCusum int
	maxCusum, maxSubArr = findMaxSubArr(arr)

	fmt.Println(maxSubArr, " ,MaxSum is:", maxCusum)
}
