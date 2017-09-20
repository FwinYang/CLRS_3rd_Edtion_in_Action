#include "MaximumBinaryHeap.h"

using namespace std;

vector<int> MaximumBinaryHeap::HeapSort()
{
	vector<int> baseBackUp = HeapBase, result;

	while (HeapBase.size()>2)
	{
		result.insert(result.begin(), HeapBase[0]);
		HeapBase[0] = HeapBase[HeapBase.size() - 1];
		HeapBase.erase(HeapBase.end()-1);
		MaxHeapify(0);
	}

	result.insert(result.begin(), HeapBase[0]);
	result.insert(result.begin(), HeapBase[1]);

	HeapBase = baseBackUp;

	return result;
}

void MaximumBinaryHeap::BuildMaxHeap()
{
	int lastestH1Node = fatherNode(HeapBase.size()-1);

	for (int i=lastestH1Node;i>=0;--i)
	{
		MaxHeapify(i);
	}
}

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

void MaximumBinaryHeap::print()
{
	cout << "最大堆目前的状态：" << endl;

	for (const auto &c : HeapBase)
	{
		cout << c << ", ";
	}
	cout << endl;
}