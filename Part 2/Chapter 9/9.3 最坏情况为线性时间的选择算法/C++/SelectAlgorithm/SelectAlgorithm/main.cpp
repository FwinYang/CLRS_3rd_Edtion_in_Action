#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//����A��Ҫ��5��������Ԫ�ء�
int Select(vector<int> &A, int index);

int main()
{
	vector<int> A = {5,2,7,12,13,9,6,8,4,10,15,1,3,14,11,16};

	cout << "ԭʼ����A��" << endl;
	for (auto a:A)
	{
		cout << a << " ";
	}
	cout << endl;

	cout<<"����A�е�7С�����ǣ�"<<Select(A, 7)<<endl;

	return 0;
}

int Select(vector<int> &A, int index)
{
	vector<vector<int>> subArrays;
	//1.���Ȱ�A���A/5�����顣
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
	//2.�Եõ������鶼���������������ÿһ�����λ�������������λ�����ɵ�һ��
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
	//3.��õ�����λ���������λ����
	{
		sort(midNums.begin(), midNums.end());
		midNum = midNums[midNums.size() / 2];
		midNums.clear();
	}
	
	int midNumIndex = 0; vector<int> LA, RA;
	//4.�������λ��Ϊ���ģ���ԭ����A�ֳ���������LA��RA��
	//��ԭ����A�б����Ԫ��С��Ԫ�ط���LA�У���ķ���RA�С�
	//��¼��λ��������ΪmidNumIndex
	{
		for (auto num : A)
		{
			if (num < midNum) LA.push_back(num);
			else RA.push_back(num);
		}

		A.clear();
		midNumIndex = LA.size()+1;
	}

	//5.���midNumIndex����index��������λ����
	if (midNumIndex == index)
	{
		return midNum;
	}
	//���index < midNumIndex,��LA���ҵ�iС��Ԫ�ء�
	else if (index < midNumIndex)
	{
		return Select(LA, index);
	}
	//���index > midNumIndex,��RA���ҵ�i-kС��Ԫ�ء�
	else
	{
		return Select(RA, index-midNumIndex+1);
	}

	return 0;
}