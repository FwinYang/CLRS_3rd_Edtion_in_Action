#include <iostream>
#include "MaximumBinaryHeap.h"

using namespace std;

int main()
{
	MaximumBinaryHeap MBHeap;

	vector<int> MBHV = {16,14,10,8,7,9,3,2,4,1};

	MBHeap.HeapBase = MBHV;

	cout << "������������������ѵ����ʣ�\n";
	for (auto i:MBHeap.HeapBase)
	{
		cout << i << " ";
	}
	cout << endl;

	while (true)
	{
		cout << "����������鿴�����������еڼ���Ԫ�ص���Ϣ������ӵ�0��Ԫ�ؿ�ʼ" << endl;
		int userInput = 0;
		cin >> userInput;

		if (userInput >= 0 && userInput<MBHeap.HeapBase.size())
		{
			cout << "���Ԫ�ص�ֵΪ" << MBHeap.HeapBase[userInput] << endl;
			int fValue = MBHeap.fatherNode(userInput), lValue = MBHeap.lChildNode(userInput), rValue = MBHeap.rChildNode(userInput);
			if (fValue != -1)cout << "���Ԫ�ظ��ڵ��ֵΪ" << fValue << endl;
			if (lValue != -1)cout << "���Ԫ�����ӽڵ��ֵΪ" << lValue << endl;
			if (rValue != -1)cout << "���Ԫ�����ӽڵ��ֵΪ" << rValue << endl;
		}
		else
		{
			cout << "Խ��" << endl;
		}
	}

	return 0;
}