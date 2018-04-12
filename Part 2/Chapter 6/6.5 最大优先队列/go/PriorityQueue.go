package main

import (
	"fmt"
)

type maximumPriorityQueue struct {
	baseArr []int
}

func (mpq *maximumPriorityQueue) getFatherValue(index int) int {
	if index != 0 {
		return mpq.baseArr[int((index+1)/2)-1]
	} else {
		return -1
	}
}

func (mpq *maximumPriorityQueue) getLChildValue(index int) int {
	if 2*index+1 < len(mpq.baseArr) {
		return mpq.baseArr[2*index+1]
	} else {
		return -1
	}
}

func (mpq *maximumPriorityQueue) getRChildValue(index int) int {
	if 2*index+2 < len(mpq.baseArr) {
		return mpq.baseArr[2*index+2]
	} else {
		return -1
	}
}

func (mpq *maximumPriorityQueue) getFatherIndex(index int) int {
	if index != 0 {
		return int((index+1)/2) - 1
	} else {
		return -1
	}
}

func (mpq *maximumPriorityQueue) getLChildIndex(index int) int {
	if 2*index+1 < len(mpq.baseArr) {
		return 2*index + 1
	} else {
		return -1
	}
}

func (mpq *maximumPriorityQueue) getRChildIndex(index int) int {
	if 2*index+2 < len(mpq.baseArr) {
		return 2*index + 2
	} else {
		return -1
	}
}

func (mpq *maximumPriorityQueue) maxHeapify(indexNeed2Fix int) {
	lChildIndex := mpq.getLChildIndex(indexNeed2Fix)
	rChildIndex := mpq.getRChildIndex(indexNeed2Fix)
	largestIndex := indexNeed2Fix

	if lChildIndex != -1 && mpq.baseArr[lChildIndex] > mpq.baseArr[indexNeed2Fix] {
		largestIndex = lChildIndex
	}

	if rChildIndex != -1 && mpq.baseArr[rChildIndex] > mpq.baseArr[largestIndex] {
		largestIndex = rChildIndex
	}

	if largestIndex != indexNeed2Fix {
		key := mpq.baseArr[largestIndex]
		mpq.baseArr[largestIndex] = mpq.baseArr[indexNeed2Fix]
		mpq.baseArr[indexNeed2Fix] = key

		mpq.maxHeapify(largestIndex)
	}
}

func (mpq *maximumPriorityQueue) heapSort() []int {
	mpqBackUp := mpq.baseArr

	var result []int
	for len(mpq.baseArr) > 2 {
		tempAddOn := []int{mpq.baseArr[0]}
		result = append(tempAddOn, result...)
		mpq.baseArr[0] = mpq.baseArr[len(mpq.baseArr)-1]
		mpq.baseArr = mpq.baseArr[0 : len(mpq.baseArr)-1]
		mpq.maxHeapify(0)
	}

	tr0 := []int{mpq.baseArr[0]}
	tr1 := []int{mpq.baseArr[1]}
	result = append(tr0, result...)
	result = append(tr1, result...)

	mpq.baseArr = mpqBackUp
	return result
}

func makeAMaxPriorityQueueFromArr(arr []int) maximumPriorityQueue {
	result := maximumPriorityQueue{arr}
	lastFatherIndex := result.getFatherIndex(len(result.baseArr) - 1)

	for i := lastFatherIndex; i >= 0; i-- {
		result.maxHeapify(i)
	}

	return result
}

func (mpq *maximumPriorityQueue) maximum() int {
	return mpq.baseArr[0]
}

func (mpq *maximumPriorityQueue) extractMax() int {
	if len(mpq.baseArr) > 0 {
		key := mpq.baseArr[0]
		mpq.baseArr[0] = mpq.baseArr[len(mpq.baseArr)-1]
		mpq.baseArr = mpq.baseArr[0 : len(mpq.baseArr)-1]
		if len(mpq.baseArr) > 0 {
			mpq.maxHeapify(0)
		}
		return key
	}
	return -1
}

func (mpq *maximumPriorityQueue) heapIncreaseKey(index, key int) {
	if key > mpq.baseArr[index] {
		mpq.baseArr[index] = key
		for index > 0 && mpq.baseArr[mpq.getFatherIndex(index)] < mpq.baseArr[index] {
			temp := mpq.baseArr[index]
			mpq.baseArr[index] = mpq.baseArr[mpq.getFatherIndex(index)]
			mpq.baseArr[mpq.getFatherIndex(index)] = temp

			index = mpq.getFatherIndex(index)
		}
	}
}

func (mpq *maximumPriorityQueue) maxHeapInsert(key int) {
	mpq.baseArr = append(mpq.baseArr, key-1)
	mpq.heapIncreaseKey(len(mpq.baseArr)-1, key)
}

func main() {

	base := []int{4, 1, 3, 2, 16, 9, 10, 14, 8, 7}
	fmt.Println("原始数组初始元素是：\n4, 1, 3, 2, 16, 9, 10, 14, 8, 7")
	mpq := makeAMaxPriorityQueueFromArr(base)

	fmt.Println("得到的最大优先队列：")
	fmt.Println(mpq)

	fmt.Println("最大优先队列的最大值为：", mpq.maximum())

	fmt.Println("删除最大值后的最大优先队列：")
	mpq.extractMax()
	fmt.Println(mpq)

	fmt.Println("把第四个元素4的值提升成11后的最大优先队列：")
	mpq.heapIncreaseKey(3, 11)
	fmt.Println(mpq)

	fmt.Println("添加一个元素24后的最大优先队列：")
	mpq.maxHeapInsert(24)
	fmt.Println(mpq)
}
