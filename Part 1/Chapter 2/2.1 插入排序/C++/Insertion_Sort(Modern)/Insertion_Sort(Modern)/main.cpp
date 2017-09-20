#include <iostream>
#include <vector>

using namespace std;

void Insertion_Sort(vector<int> &A);

int main()
{
	vector<int> A = { 2,8,6,7,1,10,5,3,9,4 };

	cout << "初始的数组：" << endl;
	for (const auto num : A)
	{
		cout << num << " ";
	}
	cout << endl;

	Insertion_Sort(A);

	cout << "经过插入排序后的数组：" << endl;
	for (const auto num : A)
	{
		cout << num << " ";
	}
	cout << endl;

	return 0;
}

void Insertion_Sort(vector<int> &A)
{
	vector<int> result = { A[0] };
	A.erase(A.begin());

	for (const auto num : A)
	{
		bool hasInserted = false;
		for (auto nowIter = result.rbegin();nowIter!=result.rend();++nowIter)
		{
			if (num>*nowIter)
			{
				hasInserted = true;
				auto insertIter = nowIter.base();
				result.insert(insertIter,num);

				break;
			}
		}

		if (!hasInserted) result.insert(result.begin(),num);
	}

	A = result;
}