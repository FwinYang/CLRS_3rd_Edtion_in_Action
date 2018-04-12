package main

import (
	"fmt"
)

type maxBinHeap struct {
	baseArr []int
}

func (mbh *maxBinHeap) fatherValue(index int) int {
	if index != 0 {
		return mbh.baseArr[int((index+1)/2)-1]
	} else {
		return -1
	}
}

func (mbh *maxBinHeap) lChildValue(index int) int {
	if 2*index+1 < len(mbh.baseArr) {
		return mbh.baseArr[2*index+1]
	} else {
		return -1
	}
}

func (mbh *maxBinHeap) rChildValue(index int) int {
	if 2*index+2 < len(mbh.baseArr) {
		return mbh.baseArr[2*index+2]
	} else {
		return -1
	}
}

func main() {
	mbp := &maxBinHeap{[]int{16, 14, 10, 8, 7, 9, 3, 2, 4, 1}}

	fmt.Println("now we have a arr which is also a maximum binary heap.")
	fmt.Println("arr:", *mbp)

	for {
		fmt.Println("please input a index, and we will show you the corresponding value.")
		inputIndex := -1
		fmt.Scanln(&inputIndex)

		if inputIndex < 0 && inputIndex >= len(mbp.baseArr) {
			fmt.Println("wrong input, exit")
			break
		} else {
			fmt.Println("value:", mbp.baseArr[inputIndex])

			if r1 := mbp.fatherValue(inputIndex); r1 != -1 {
				fmt.Println("father value:", r1)
			}
			if r2 := mbp.lChildValue(inputIndex); r2 != -1 {
				fmt.Println("left child value:", r2)
			}
			if r3 := mbp.rChildValue(inputIndex); r3 != -1 {
				fmt.Println("right child value:", r3)
			}
		}
	}
}
