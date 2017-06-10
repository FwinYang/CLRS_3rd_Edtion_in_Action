#include <iostream>
#include <vector>

using namespace std;

void Merge_Sort(int(&A)[11], int p, int r);
void Merge(int(&A)[11],int q,int p,int r);

int main()
{
	int A[11] = { 2,8,6,7,1,10,5,3,11,9,4 };

	cout << "初始的数组：" << endl;
	for (const auto num : A)
	{
		cout << num << " ";
	}
	cout << endl;

	Merge_Sort(A,0,10);

	cout << "经过归并排序后的数组：" << endl;
	for (const auto num : A)
	{
		cout << num << " ";
	}
	cout << endl;

	return 0;
}

void Merge_Sort(int(&A)[11], int p, int r)
{
	if (p<r)
	{
		int q = (p+r)/2;
		if (p<q) Merge_Sort(A, p, q);
		if (q+1<r) Merge_Sort(A, q+1, r);
		Merge(A,p,q,r);
	}
}

void Merge(int(&A)[11], int q, int p, int r)
{
	vector<int> L(begin(A) + q, begin(A) + p+1);
	vector<int> R(begin(A) + p+1, begin(A) + r+1);
	
	for(int k = q,i = 0,j = 0;k <= r;++k)
	{
		if (i >= L.size())
		{
			A[k] = R[j]; ++j;
		}
		else if(j >= R.size())
		{
			A[k] = L[i]; ++i;
		}
		else
		{
			if (L[i] >= R[j]) 
			{
				A[k] = R[j]; ++j;
			}
			else
			{
				A[k] = L[i]; ++i;
			}
		}
	}
}