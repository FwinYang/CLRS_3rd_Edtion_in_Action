#include <iostream>

using namespace std;

void Bubble_Sort(int(&A)[10], int length);

int main()
{
	int A[10] = { 2,8,6,7,1,10,5,3,9,4 };

	cout << "初始的数组：" << endl;
	for (const auto num : A)
	{
		cout << num << " ";
	}
	cout << endl;

	Bubble_Sort(A,10);

	cout << "经过归并排序后的数组：" << endl;
	for (const auto num : A)
	{
		cout << num << " ";
	}
	cout << endl;

	return 0;
}

void Bubble_Sort(int(&A)[10], int length)
{
	for (int i=0;i<length-1;++i)
	{
		for (int j=length-1;j>i;--j)
		{
			if (A[j]<A[j-1])
			{
				int key = A[j];
				A[j] = A[j - 1];
				A[j - 1] = key;
			}
		}
	}
}