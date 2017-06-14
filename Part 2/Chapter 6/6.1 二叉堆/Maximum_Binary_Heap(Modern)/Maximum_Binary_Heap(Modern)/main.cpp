#include <iostream>
#include "MaximumBinaryHeap.h"

using namespace std;

int main()
{
	MaximumBinaryHeap MBHeap;

	vector<int> MBHV = {16,14,10,8,7,9,3,2,4,1};

	MBHeap.HeapBase = MBHV;

	cout << "以下这个数组满足最大堆的性质：\n";
	for (auto i:MBHeap.HeapBase)
	{
		cout << i << " ";
	}
	cout << endl;

	while (true)
	{
		cout << "请输入你想查看的这个二叉堆中第几个元素的信息，数组从第0个元素开始" << endl;
		int userInput = 0;
		cin >> userInput;

		if (userInput >= 0 && userInput<MBHeap.HeapBase.size())
		{
			cout << "这个元素的值为" << MBHeap.HeapBase[userInput] << endl;
			int fValue = MBHeap.fatherNode(userInput), lValue = MBHeap.lChildNode(userInput), rValue = MBHeap.rChildNode(userInput);
			if (fValue != -1)cout << "这个元素父节点的值为" << fValue << endl;
			if (lValue != -1)cout << "这个元素左子节点的值为" << lValue << endl;
			if (rValue != -1)cout << "这个元素右子节点的值为" << rValue << endl;
		}
		else
		{
			cout << "越界" << endl;
		}
	}

	return 0;
}