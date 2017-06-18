#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

void RadixSort(vector<int> &A);

vector<int> Count_Sort(const vector<int> &A, int index);

int main()
{
	vector<int> A = { 329, 457, 657, 839, 436, 720, 355};

	cout << "初始的数组：" << endl;
	for (const auto num : A)
	{
		cout << num << " ";
	}
	cout << endl;

	RadixSort(A);

	cout << "经过基数排序后的数组：" << endl;
	for (const auto num : A)
	{
		cout << num << " ";
	}
	cout << endl;

	return 0;
}

void RadixSort(vector<int> &A)
{
	for (int i = 2;i>=0;--i)
	{
		A = Count_Sort(A,i);
	}
}

//这个作为稳定排序算法的计数排序，它按照A中每个元素的第index位元素的值的大小进行排序。
vector<int> Count_Sort(const vector<int> &A, int index)
{
	vector<int> resultArray(10 + A.size(), -1);

	for (const auto &num : A)
	{
		stringstream ss; ss << num;
		string tempS; ss >> tempS;
		ss.clear();
		int indexNum = 0;
		ss << tempS[index];
		ss >> indexNum;

		int i = indexNum;
		while(resultArray[i]!=-1)
		{
			++i;
		}
		resultArray[i] = num;
	}

	for (auto begIter=resultArray.begin();begIter!=resultArray.end();)
	{
		if (*begIter==-1)
		{
			begIter = resultArray.erase(begIter);
		}
		else
		{
			++begIter;
		}
	}

	return resultArray;
}