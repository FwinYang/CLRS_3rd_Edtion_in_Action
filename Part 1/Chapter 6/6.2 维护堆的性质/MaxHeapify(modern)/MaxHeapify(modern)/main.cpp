#include <iostream>
#include "MaximumBinaryHeap.h"

using namespace std;

int main()
{
	MaximumBinaryHeap MBH;
	MBH.HeapBase = {16,4,10,14,7,9,3,2,8,1};

	cout << "�������ѵĳ�ʼԪ���ǣ�\n16, 4, 10, 14, 7, 9, 3, 2, 8, 1" << endl;
	cout << "���е�2��Ԫ�أ�ֵΪ��4��λ���Ǵ���ģ���2��Ԫ�ص����������͸��ڵ����������״̬����ȷ�ģ�������������" << endl;

	MBH.MaxHeapify(1);

	cout << "ά�����ʺ����ѵ�״̬��" << endl;

	for (const auto &c:MBH.HeapBase)
	{
		cout << c << ", ";
	}
	cout << endl;

	return 0;
}