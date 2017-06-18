#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void BucketSort(vector<double> &A);

int main()
{
	vector<double> A = { 0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68 };

	cout << "初始的数组：" << endl;
	for (const auto num : A)
	{
		cout << num << " ";
	}
	cout << endl;

	BucketSort(A);

	cout << "经过桶排序后的数组：" << endl;
	for (const auto num : A)
	{
		cout << num << " ";
	}
	cout << endl;

	return 0;
}

void BucketSort(vector<double> &A)
{
	vector<list<double>> buckets(A.size());
	
	for (int i = 0;i<A.size();++i)
	{
		buckets[A.size()*A[i]].push_back(A[i]);
	}

	for (int i = 0;i<buckets.size();++i)
	{
		buckets[i].sort();
	}

	A.clear();
	for (auto bk : buckets)
	{
		for (auto val : bk)
		{
			A.push_back(val);
		}
	}
}