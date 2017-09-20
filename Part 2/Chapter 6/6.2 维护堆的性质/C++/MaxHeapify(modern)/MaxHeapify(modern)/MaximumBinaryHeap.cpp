#include "MaximumBinaryHeap.h"

using namespace std;

void MaximumBinaryHeap::MaxHeapify(const int &index)
{
	int lNumIndex = lChildNode(index);
	int rNumIndex = rChildNode(index);

	int largestNumIndex = index;

	if (lNumIndex != -1) HeapBase[lNumIndex] > HeapBase[index] ? largestNumIndex = lNumIndex: largestNumIndex = index;
	if (rNumIndex != -1) HeapBase[rNumIndex] > HeapBase[largestNumIndex] ? largestNumIndex = rNumIndex : 0 ;

	if (largestNumIndex!=index)
	{
		int key = HeapBase[largestNumIndex]; HeapBase[largestNumIndex] = HeapBase[index]; HeapBase[index] = key;

		MaxHeapify(largestNumIndex);
	}
}