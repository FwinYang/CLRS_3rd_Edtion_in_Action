#include "MaximumBinaryHeap.h"

using namespace std;

int main()
{
	vector<int> base = { 4,1,3,2,16,9,10,14,8,7 };

	cout << "ԭʼ�����ʼԪ���ǣ�\n4, 1, 3, 2, 16, 9, 10, 14, 8, 7" << endl;
	cout << "��������齨һ�������" << endl;

	MaximumBinaryHeap MBH(base);

	MBH.print();

	return 0;
}