#include <iostream>
#include <vector>
#include <random>

using namespace std;

void Random_Quick_Sort(vector<int> &A, int p, int r);

int Partition(vector<int> &A, int p, int r);

int main()
{
	vector<int> A = { 2,8,7,1,3,5,6,4 };

	cout << "初始的数组：" << endl;
	for (const auto num : A)
	{
		cout << num << " ";
	}
	cout << endl;

	Random_Quick_Sort(A, 0, A.size()-1);

	cout << "经过快速排序后的数组：" << endl;
	for (const auto num : A)
	{
		cout << num << " ";
	}
	cout << endl;

	return 0;
}

void Random_Quick_Sort(vector<int> &A, int p, int r)
{
	if (p < r)
	{
		int q = Partition(A, p, r);
		Random_Quick_Sort(A, p, q - 1);
		Random_Quick_Sort(A, q + 1, r);
	}
}

int Partition(vector<int> &A, int p, int r)
{
	///只有这里和快速排序不同///
	uniform_int_distribution<unsigned> uid(p,r);
	static default_random_engine e;
	int tk = uid(e);
	int tp = A[tk]; A[tk] = A[r]; A[r] = tp;
	////////////////////////////

	int pivotKey = A[r];
	int i = p-1;
	for (int j = p;j < r;++j)
	{
		if (A[j]<= pivotKey)
		{
			++i;
			int temp = A[i]; A[i] = A[j]; A[j] = temp;
		}
	}
	int temp = A[i+1]; A[i+1] = A[r]; A[r] = temp;
	return i + 1;
}