#include <iostream>
#include <vector>

using namespace std;

void Quick_Sort(vector<int> &A, int p, int r);

int Partition(vector<int> &A, int p, int r);

int main()
{
	vector<int> A = { 2,8,7,1,3,5,6,4 };

	cout << "��ʼ�����飺" << endl;
	for (const auto num : A)
	{
		cout << num << " ";
	}
	cout << endl;

	Quick_Sort(A, 0, A.size()-1);

	cout << "�����������������飺" << endl;
	for (const auto num : A)
	{
		cout << num << " ";
	}
	cout << endl;

	return 0;
}

void Quick_Sort(vector<int> &A, int p, int r)
{
	if (p < r)
	{
		int q = Partition(A, p, r);
		Quick_Sort(A, p, q - 1);
		Quick_Sort(A, q + 1, r);
	}
}

int Partition(vector<int> &A, int p, int r)
{
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