#include "MaximumBinaryHeap.h"

using namespace std;

int main()
{
	vector<int> base = { 4,1,3,2,16,9,10,14,8,7 }, result;

	cout << "ԭʼ�����ʼԪ���ǣ�\n4, 1, 3, 2, 16, 9, 10, 14, 8, 7" << endl;

	MaximumBinaryHeap MBH(base);

	cout << "������õ������飺" << endl;

	result = MBH.HeapSort();

	for (const auto &c : result)
	{
		cout << c << ", ";
	}
	cout << endl;

	return 0;
}