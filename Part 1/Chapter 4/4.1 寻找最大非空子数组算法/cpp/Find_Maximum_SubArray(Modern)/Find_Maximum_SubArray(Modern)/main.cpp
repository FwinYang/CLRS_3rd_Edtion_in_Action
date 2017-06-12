#include <iostream>
#include <vector>

using namespace std;

int Find_Maximum_SubArray(const vector<int> &A, vector<int> &maximumSubArray);
void Find_Max_Crossing_SubArray(const vector<int> &pendingSubArray, vector<int> &mSub, int &maxSum);

int main()
{
	vector<int> A = { 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 },result;

	cout << "原始数组：" << endl;
	for (const auto num : A)
	{
		cout << num << " ";
	}
	cout << endl;

	int sum = Find_Maximum_SubArray(A, result);

	cout << "数组A的最大子数组为：" << endl;
	for (const auto num : result)
	{
		cout << num << " ";
	}
	cout << "\n数组A的最大子数组之和为：" <<sum<< endl;
	cout << endl;

	return 0;
}

int Find_Maximum_SubArray(const vector<int> &A, vector<int> &maximumSubArray)
{
	if (A.size() == 1)
	{
		maximumSubArray = A; return A[0];
	}
	else
	{
		int midNum = A.size() / 2;
		vector<int> tempLArray(A.begin(), A.begin() + midNum);
		vector<int> tempRArray(A.begin() + midNum, A.end());

		vector<int> lMaxSubArray, rMaxSubArray, mMaxSubArray;
		int lMaxSum = Find_Maximum_SubArray(tempLArray, lMaxSubArray);
		int rMaxSum = Find_Maximum_SubArray(tempRArray, rMaxSubArray);
		int mMaxSum = 0;
		Find_Max_Crossing_SubArray(A, mMaxSubArray, mMaxSum);

		if (lMaxSum >= rMaxSum&&lMaxSum >= mMaxSum)
		{
			maximumSubArray = lMaxSubArray;
			return lMaxSum;
		}
		else if (rMaxSum >= lMaxSum&&lMaxSum >= mMaxSum)
		{
			maximumSubArray = rMaxSubArray;
			return rMaxSum;
		}
		else
		{
			maximumSubArray = mMaxSubArray;
			return mMaxSum;
		}
	}
}

void Find_Max_Crossing_SubArray(const vector<int> &pendingSubArray, vector<int> &mSub, int &maxSum)
{
	int midNum = pendingSubArray.size() / 2;

	vector<int> tempLArray(pendingSubArray.begin(), pendingSubArray.begin() + midNum);
	vector<int> tempRArray(pendingSubArray.begin() + midNum, pendingSubArray.end());

	vector<int> tempMLArray, tempMRArray;
	int lMSum = tempLArray[tempLArray.size()-1]-1, rMSum = tempRArray[0]-1;

	int allLSum = 0;
	for (int i= tempLArray.size()-1;i>=0;--i)
	{
		allLSum += tempLArray[i];

		if (allLSum>lMSum)
		{
			lMSum = allLSum;
			vector<int> mLA(tempLArray.begin()+i, tempLArray.end());
			tempMLArray = mLA;
		}
	}

	int allRSum = 0;
	for (int i =  0; i < tempRArray.size(); ++i)
	{
		allRSum += tempRArray[i];

		if (allRSum>rMSum)
		{
			rMSum = allRSum;
			vector<int> mRA(tempRArray.begin(), tempRArray.begin()+i+1);
			tempMRArray = mRA;
		}
	}

	maxSum = lMSum + rMSum;
	mSub = tempMLArray;
	for (auto num: tempMRArray)
	{
		mSub.push_back(num);
	}
}