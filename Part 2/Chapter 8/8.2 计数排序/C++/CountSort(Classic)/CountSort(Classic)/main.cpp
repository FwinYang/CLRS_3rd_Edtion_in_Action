#include <iostream>
#include <vector>

using namespace std;

void Count_Sort(const vector<int> &A, vector<int> &B, int k);

int main()
{
	vector<int> A = { 2,8,6,7,1,4,10,5,3,9,6,4 },B(A.size(),0);

	cout << "初始的数组：" << endl;
	for (const auto num : A)
	{
		cout << num << " ";
	}
	cout << endl;

	Count_Sort(A, B, 100);

	cout << "经过计数排序后的数组：" << endl;
	for (const auto num : B)
	{
		cout << num << " ";
	}
	cout << endl;

	return 0;
}

void Count_Sort(const vector<int> &A, vector<int> &B, int k)
{
	vector<int> C(k, 0);

	for (const auto &num : A)
	{
		C[num] += 1;
	}

	for (int i = 1;i<k;++i)
	{
		C[i] += C[i - 1];
	}

	for (int j = A.size()-1;j>=0;--j)
	{
		B[C[A[j]]-1] = A[j];
		--C[A[j]];
	}
}