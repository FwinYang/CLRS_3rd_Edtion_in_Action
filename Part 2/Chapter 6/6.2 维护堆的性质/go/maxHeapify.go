package main

import (
	"fmt"
)

type maxBinHeap struct {
	baseArr []int
}

func (mbh *maxBinHeap) getFatherValue(index int) int {
	if index != 0 {
		return mbh.baseArr[int((index+1)/2)-1]
	} else {
		return -1
	}
}

func (mbh *maxBinHeap) getLChildValue(index int) int {
	if 2*index+1 < len(mbh.baseArr) {
		return mbh.baseArr[2*index+1]
	} else {
		return -1
	}
}

func (mbh *maxBinHeap) getRChildValue(index int) int {
	if 2*index+2 < len(mbh.baseArr) {
		return mbh.baseArr[2*index+2]
	} else {
		return -1
	}
}

func (mbh *maxBinHeap) getFatherIndex(index int) int {
	if index != 0 {
		return int((index+1)/2) - 1
	} else {
		return -1
	}
}

func (mbh *maxBinHeap) getLChildIndex(index int) int {
	if 2*index+1 < len(mbh.baseArr) {
		return 2*index + 1
	} else {
		return -1
	}
}

func (mbh *maxBinHeap) getRChildIndex(index int) int {
	if 2*index+2 < len(mbh.baseArr) {
		return 2*index + 2
	} else {
		return -1
	}
}

func (mbh *maxBinHeap) maxHeapify(indexNeed2Fix int) {
	lChildIndex := mbh.getLChildIndex(indexNeed2Fix)
	rChildIndex := mbh.getRChildIndex(indexNeed2Fix)
	largestIndex := indexNeed2Fix

	if lChildIndex != -1 && mbh.baseArr[lChildIndex] > mbh.baseArr[indexNeed2Fix] {
		largestIndex = lChildIndex
	}

	if rChildIndex != -1 && mbh.baseArr[rChildIndex] > mbh.baseArr[largestIndex] {
		largestIndex = rChildIndex
	}

	if largestIndex != indexNeed2Fix {
		key := mbh.baseArr[largestIndex]
		mbh.baseArr[largestIndex] = mbh.baseArr[indexNeed2Fix]
		mbh.baseArr[indexNeed2Fix] = key

		mbh.maxHeapify(largestIndex)
	}
}

func main() {
	mbp := &maxBinHeap{[]int{16, 4, 10, 14, 7, 9, 3, 2, 8, 1}}

	fmt.Println("at first we have a arr which is not a maximum binary heap.")
	fmt.Println("arr:", *mbp)

	mbp.maxHeapify(1)

	fmt.Println("now it is a maximum binary heap.")
	fmt.Println("arr:", *mbp)
}
