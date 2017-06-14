#include <iostream>
#include "MaximumBinaryHeap.h"

using namespace std;

int main()
{
	MaximumBinaryHeap MBH;
	MBH.HeapBase = {16,4,10,14,7,9,3,2,8,1};

	cout << "这个二叉堆的初始元素是：\n16, 4, 10, 14, 7, 9, 3, 2, 8, 1" << endl;
	cout << "其中第2号元素（值为）4的位置是错误的，但2号元素的左右子树和根节点的右子树的状态是正确的，满足最大堆性质" << endl;

	MBH.MaxHeapify(1);

	cout << "维持性质后最大堆的状态：" << endl;

	for (const auto &c:MBH.HeapBase)
	{
		cout << c << ", ";
	}
	cout << endl;

	return 0;
}