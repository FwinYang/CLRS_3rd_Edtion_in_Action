#ifndef _MAXIMUM_BINARY_HRAP_
#define _MAXIMUM_BINARY_HRAP_

#include <vector>

class MaximumBinaryHeap
{
public:
	int fatherNode(int index) { return index != 0 ? HeapBase[(index + 1) / 2 - 1] : -1; }
	int lChildNode(int index) { return 2 * index+1<HeapBase.size() ? HeapBase[2 * index + 1] : -1; };
	int rChildNode(int index) { return 2*index+2 <HeapBase.size() ? HeapBase[2 * index + 2] : -1; };

	std::vector<int> HeapBase;
};

#endif