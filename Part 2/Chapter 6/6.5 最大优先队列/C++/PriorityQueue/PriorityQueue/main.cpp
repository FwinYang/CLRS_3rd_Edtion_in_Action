#include "MaximumPriorityQueue.h"

using namespace std;

int main()
{
	vector<int> base = { 4,1,3,2,16,9,10,14,8,7 }, result;
	cout << "ԭʼ�����ʼԪ���ǣ�\n4, 1, 3, 2, 16, 9, 10, 14, 8, 7" << endl;
	MaximumPriorityQueue MPQ(base);

	cout << "�õ���������ȶ��У�" << endl;
	MPQ.print();

	cout << "������ȶ��е����ֵΪ��" << MPQ.Maximum()<<endl;

	cout << "ɾ�����ֵ���������ȶ���" << endl;
	MPQ.ExtractMax();
	MPQ.print();

	cout << "�ѵ��ĸ�Ԫ��2��ֵ������11"<<endl;
	MPQ.HeapIncreaseKey(3,11);
	MPQ.print();

	cout << "���һ��Ԫ��24" << endl;
	MPQ.MaxHeapInsert(24);
	MPQ.print();

	return 0;
}