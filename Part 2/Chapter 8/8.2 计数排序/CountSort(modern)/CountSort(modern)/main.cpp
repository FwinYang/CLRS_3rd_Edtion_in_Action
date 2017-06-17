#include <iostream>
#include <vector>

using namespace std;

vector<int> Count_Sort(const vector<int> &A);

int main()
{
	vector<int> A = { 2,8,6,7,1,4,10,5,3,9,6,4 };

	cout << "��ʼ�����飺" << endl;
	for (const auto num : A)
	{
		cout << num << " ";
	}
	cout << endl;

	A = Count_Sort(A);

	cout << "�����������������飺" << endl;
	for (const auto num : A)
	{
		cout << num << " ";
	}
	cout << endl;

	return 0;
}

vector<int> Count_Sort(const vector<int> &A)
{
	//����������������ɵ�Ԫ�ص����ֵ��1 ~ 100��
	int k = 101;

	vector<int> countArray(k,0),result;
	for (const auto &num : A)
	{
		countArray[num] += 1;
	}

	for (int i = 1;i<countArray.size();++i)
	{
		for (int j = 0;j<countArray[i];++j)
		{
			result.push_back(i);
		}
	}

	return result;
}