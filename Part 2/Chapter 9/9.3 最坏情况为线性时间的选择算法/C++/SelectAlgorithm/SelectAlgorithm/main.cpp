#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//数组A需要有5个或更多的元素。
int Select(vector<int> &A, int index);

int main()
{
	vector<int> A = {5,2,7,12,13,9,6,8,4,10,15,1,3,14,11,16};

	cout << "原始数组A：" << endl;
	for (auto a:A)
	{
		cout << a << " ";
	}
	cout << endl;

	cout<<"数组A中第7小的数是："<<Select(A, 7)<<endl;

	return 0;
}

int Select(vector<int> &A, int index)
{
	vector<vector<int>> subArrays;
	//1.首先把A拆成A/5个数组。
	{
		int i = 0;
		for (int j = 0; j < A.size()/5; i += 5,++j)
		{
			vector<int> temp(A.begin() + i, A.begin() + i + 5);
			subArrays.push_back(temp);
		}

		if (i < A.size()) { vector<int> temp(A.begin() + i, A.end()); subArrays.push_back(temp); }
	}
	
	vector<int> midNums;
	//2.对得到的数组都进行排序，排序后求每一组的中位数，把求出的中位数归纳到一起。
	{
		for (int i = 0; i<subArrays.size(); ++i) { sort(subArrays[i].begin(), subArrays[i].end()); }

		for (auto arr:subArrays)
		{
			int midNum = arr[arr.size()/2];
			midNums.push_back(midNum);
		}
		subArrays.clear();
	}

	int midNum = 0;
	//3.求得到的中位数数组的中位数。
	{
		sort(midNums.begin(), midNums.end());
		midNum = midNums[midNums.size() / 2];
		midNums.clear();
	}
	
	int midNumIndex = 0; vector<int> LA, RA;
	//4.以这个中位数为中心，把原数组A分成两个数组LA和RA。
	//把原数组A中比这个元素小的元素放在LA中，大的放在RA中。
	//记录中位数的序数为midNumIndex
	{
		for (auto num : A)
		{
			if (num < midNum) LA.push_back(num);
			else RA.push_back(num);
		}

		A.clear();
		midNumIndex = LA.size()+1;
	}

	//5.如果midNumIndex等于index，返回中位数。
	if (midNumIndex == index)
	{
		return midNum;
	}
	//如果index < midNumIndex,在LA里找第i小的元素。
	else if (index < midNumIndex)
	{
		return Select(LA, index);
	}
	//如果index > midNumIndex,在RA里找第i-k小的元素。
	else
	{
		return Select(RA, index-midNumIndex+1);
	}

	return 0;
}