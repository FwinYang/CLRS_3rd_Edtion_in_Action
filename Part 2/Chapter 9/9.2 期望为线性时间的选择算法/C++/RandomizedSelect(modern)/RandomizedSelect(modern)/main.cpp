#include <iostream>
#include <vector>
#include <random>

using namespace std;

int RandomizedSelect(vector<int> &A, int p, int r, int index);

int RandomizedPartition(vector<int> &A, int p, int r);

int main()
{
	vector<int> A = { 2,8,7,1,3,5,6,4 };

	cout << "初始的数组：" << endl;
	for (const auto num : A)
	{
		cout << num << " ";
	}
	cout << endl;

	cout << "这个数组中第4小的元素为：" << endl;
	cout << RandomizedSelect(A, 0, A.size() - 1, 4) << endl;

	return 0;
}

int RandomizedSelect(vector<int> &A, int p, int r, int index)
{
	if (p == r)return A[p];
	else if (p < r)
	{
		int q = RandomizedPartition(A, p, r);
		int k = q - p + 1;
		if (index == k) return A[q];
		else if (index < k) return RandomizedSelect(A, p, q - 1, index);
		else return RandomizedSelect(A, q + 1, r, index - k);
	}
}

int RandomizedPartition(vector<int> &A, int p, int r)
{
	///使用了S++STL中的随机数引擎///
	uniform_int_distribution<unsigned> uid(p, r);
	static default_random_engine e;
	int tk = uid(e);
	int tp = A[tk]; A[tk] = A[r]; A[r] = tp;
	////////////////////////////////

	int pivotKey = A[r];
	int i = p - 1;
	for (int j = p; j < r; ++j)
	{
		if (A[j] <= pivotKey)
		{
			++i;
			int temp = A[i]; A[i] = A[j]; A[j] = temp;
		}
	}
	int temp = A[i + 1]; A[i + 1] = A[r]; A[r] = temp;
	return i + 1;
}