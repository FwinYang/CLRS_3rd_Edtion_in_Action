#include <iostream>
#include <vector>

using namespace std;

vector<int> Merge_Sort(vector<int> A);

vector<int> Merge(vector<int> PartL, vector<int> PartR);

int main()
{
	vector<int> A = { 2,8,6,7,1,10,5,3,11,9,4 };

	cout << "初始的数组：" << endl;
	for (const auto num : A)
	{
		cout << num << " ";
	}
	cout << endl;

	A = Merge_Sort(A);

	cout << "经过归并排序后的数组：" << endl;
	for (const auto num : A)
	{
		cout << num << " ";
	}
	cout << endl;

	return 0;
}

vector<int> Merge_Sort(vector<int> A)
{
	if (A.size() > 1)
	{
		auto midIter = A.begin() + (A.size() / 2);
		vector<int> PartL(A.begin(), midIter);
		vector<int> PartR(midIter, A.end());
		
		return Merge(Merge_Sort(PartL), Merge_Sort(PartR));
	}
	else
		return A;
}

vector<int> Merge(vector<int> PartL, vector<int> PartR)
{
	vector<int> result;
	auto iterL = PartL.begin(), iterR = PartR.begin();
	while (!(PartL.empty()&&PartR.empty()))
	{
		if (PartL.empty() || !PartR.empty() && *iterL > *iterR)
		{
			result.push_back(*iterR);
			iterR = PartR.erase(iterR);
		}
		else if(PartR.empty() || !PartL.empty() && *iterL <= *iterR)
		{
			result.push_back(*iterL);
			iterL = PartL.erase(iterL);
		}
	}

	return result;
}