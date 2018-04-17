package main

import "fmt"

type stack struct {
	arr []int
}

func (s stack) isEmpty() (result bool) {
	if len(s.arr) == 0 {
		result = true
	} else {
		result = false
	}
	return
}

func (s *stack) push(i int) {
	(*s).arr = append((*s).arr, i)
}

func (s stack) String() string {
	return fmt.Sprintf("%v", s.arr)
}

func (s *stack) pop() int {
	result := (*s).arr[len((*s).arr)-1]
	(*s).arr = (*s).arr[0 : len((*s).arr)-1]
	return result
}

func main() {
	s := stack{make([]int, 0)}

	s.push(1)
	s.push(2)
	fmt.Println(s)

	s.pop()
	fmt.Println(s)

	s.pop()
	fmt.Println(s)

	b := s.isEmpty()
	fmt.Println(b)
}
