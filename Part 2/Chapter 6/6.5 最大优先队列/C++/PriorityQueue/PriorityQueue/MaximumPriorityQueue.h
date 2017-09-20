#ifndef _MAXIMUM_PRIORITY_QUEUE_
#define _MAXIMUM_PRIORITY_QUEUE_

#include <iostream>
#include <vector>

class MaximumPriorityQueue
{
public:
	//������������ȶ��еķ���
	int Maximum() { return HeapBase[0]; }
	int ExtractMax();
	void HeapIncreaseKey(int index, int key);
	void MaxHeapInsert(int key);

	//���º������Ѿ�ʵ�ֹ��ĶѲ���
	MaximumPriorityQueue() = default;
	MaximumPriorityQueue(const std::vector<int> &base) { HeapBase = base; BuildMaxHeap(); }

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