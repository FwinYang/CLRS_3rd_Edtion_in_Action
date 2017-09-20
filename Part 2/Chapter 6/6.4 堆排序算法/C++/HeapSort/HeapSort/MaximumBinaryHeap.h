#ifndef _MAXIMUM_BINARY_HRAP_
#define _MAXIMUM_BINARY_HRAP_

#include <iostream>
#include <vector>

class MaximumBinaryHeap
{
public:
	MaximumBinaryHeap() = default;
	MaximumBinaryHeap(const std::vector<int> &base) { HeapBase = base; BuildMaxHeap(); }

	int fatherNode(const int &index) { return index != 0 ? (index + 1) / 2 - 1 : -1; }
	int lChildNode(const int &index) { return 2 * index + 1 < HeapBase.size() ? 2 * index + 1 : -1; };
	int rChildNode(const int &index) { return 2 * index + 2 < HeapBase.size() ? 2 * index + 2 : -1; };

	std::vector<int> HeapSort();

	void BuildMaxHeap();
	void MaxHeapify(const int &index);
	void print();

private:
	std::vector<int> HeapBase;
};

#endif