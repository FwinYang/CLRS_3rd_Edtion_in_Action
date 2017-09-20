#include <iostream>
#include <vector>

using namespace std;

int Minimum(const vector<int> &A);

int main()
{
	vector<int> A = { 8,6,7,1,4,10,5,3,9,6,4,0,99 };

	cout << "初始的数组：" << endl;
	for (const auto num : A)
	{
		cout << num << " ";
	}
	cout << endl;

	cout << "这个数组第1个顺序统计量的值：" << endl;
	
	cout << Minimum(A) << endl;

	return 0;
}

int Minimum(const vector<int> &A)
{
	int result = A[0];
	for (const auto num : A)
	{
		if (num < result) result = num;
	}
	return result;
}