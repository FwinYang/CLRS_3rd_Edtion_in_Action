#include "MaximumPriorityQueue.h"

using namespace std;

int main()
{
	vector<int> base = { 4,1,3,2,16,9,10,14,8,7 }, result;
	cout << "原始数组初始元素是：\n4, 1, 3, 2, 16, 9, 10, 14, 8, 7" << endl;
	MaximumPriorityQueue MPQ(base);

	cout << "得到的最大优先队列：" << endl;
	MPQ.print();

	cout << "最大优先队列的最大值为：" << MPQ.Maximum()<<endl;

	cout << "删除最大值后的最大优先队列" << endl;
	MPQ.ExtractMax();
	MPQ.print();

	cout << "把第四个元素2的值提升成11"<<endl;
	MPQ.HeapIncreaseKey(3,11);
	MPQ.print();

	cout << "添加一个元素24" << endl;
	MPQ.MaxHeapInsert(24);
	MPQ.print();

	return 0;
}