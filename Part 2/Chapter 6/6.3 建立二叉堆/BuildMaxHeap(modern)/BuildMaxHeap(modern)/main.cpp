#include "MaximumBinaryHeap.h"

using namespace std;

int main()
{
	vector<int> base = { 4,1,3,2,16,9,10,14,8,7 };

	cout << "原始数组初始元素是：\n4, 1, 3, 2, 16, 9, 10, 14, 8, 7" << endl;
	cout << "用这个数组建一个二叉堆" << endl;

	MaximumBinaryHeap MBH(base);

	MBH.print();

	return 0;
}