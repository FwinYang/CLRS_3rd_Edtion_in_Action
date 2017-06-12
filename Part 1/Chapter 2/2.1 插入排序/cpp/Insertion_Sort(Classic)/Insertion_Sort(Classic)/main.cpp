#include <iostream>

using namespace std;

void Insertion_Sort(int(&A)[10],int length);

int main()
{
	int A[10] = {2,8,6,7,1,10,5,3,9,4};

	cout << "初始的数组：" << endl;
	for (const auto num : A)
	{
		cout << num << " ";
	}
	cout << endl;

	Insertion_Sort(A,10);

	cout << "经过插入排序后的数组：" << endl;
	for (const auto num : A)
	{
		cout << num << " ";
	}
	cout << endl;

	return 0;
}

void Insertion_Sort(int(&A)[10],int length)
{
	for (int j=1; j<=length-1; ++j)
	{
		int key = A[j];
		int i = j - 1;
		while (i>=0 && A[i]>key)
		{
			A[i + 1] = A[i];
			--i;
		}
		A[i + 1] = key;
	}
}