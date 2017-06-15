#include "MaximumPriorityQueue.h"

using namespace std;

int MaximumPriorityQueue::ExtractMax()
{
	if (HeapBase.empty())
	{
		//throw ....over range
		return -1;
	}
	else
	{
		int key = HeapBase[0];
		HeapBase[0] = HeapBase[HeapBase.size() - 1];
		auto endIter = HeapBase.end() - 1;
		HeapBase.erase(endIter);
		if (!HeapBase.empty())
		{
			MaxHeapify(0);
		}

		return key;
	}
}

void MaximumPriorityQueue::HeapIncreaseKey(int index, int key)
{
	if (key < HeapBase[index])return;
	else
	{
		HeapBase[index] = key;
		while (index > 0 && HeapBase[fatherNode(index)]<HeapBase[index])
		{
			int temp = HeapBase[index];
			HeapBase[index] = HeapBase[fatherNode(index)];
			HeapBase[fatherNode(index)] = temp;

			index = fatherNode(index);
		}
	}
}

void MaximumPriorityQueue::MaxHeapInsert(int key)
{
	HeapBase.push_back(-999999999);
	HeapIncreaseKey(HeapBase.size()-1,key);
}

vector<int> MaximumPriorityQueue::HeapSort()
{
	vector<int> baseBackUp = HeapBase, result;

	while (HeapBase.size()>2)
	{
		result.insert(result.begin(), HeapBase[0]);
		HeapBase[0] = HeapBase[HeapBase.size() - 1];
		HeapBase.erase(HeapBase.end() - 1);
		MaxHeapify(0);
	}

	result.insert(result.begin(), HeapBase[0]);
	result.insert(result.begin(), HeapBase[1]);

	HeapBase = baseBackUp;

	return result;
}

void MaximumPriorityQueue::BuildMaxHeap()
{
	int lastestH1Node = fatherNode(HeapBase.size() - 1);

	for (int i = lastestH1Node; i >= 0; --i)
	{
		MaxHeapify(i);
	}
}

void MaximumPriorityQueue::MaxHeapify(const int &index)
{
	int lNumIndex = lChildNode(index);
	int rNumIndex = rChildNode(index);

	int largestNumIndex = index;

	if (lNumIndex != -1) HeapBase[lNumIndex] > HeapBase[index] ? largestNumIndex = lNumIndex : largestNumIndex = index;
	if (rNumIndex != -1) HeapBase[rNumIndex] > HeapBase[largestNumIndex] ? largestNumIndex = rNumIndex : 0;

	if (largestNumIndex != index)
	{
		int key = HeapBase[largestNumIndex]; HeapBase[largestNumIndex] = HeapBase[index]; HeapBase[index] = key;

		MaxHeapify(largestNumIndex);
	}
}

void MaximumPriorityQueue::print()
{
	cout << "最大优先队列目前的状态：" << endl;

	for (const auto &c : HeapBase)
	{
		cout << c << ", ";
	}
	cout << endl;
}