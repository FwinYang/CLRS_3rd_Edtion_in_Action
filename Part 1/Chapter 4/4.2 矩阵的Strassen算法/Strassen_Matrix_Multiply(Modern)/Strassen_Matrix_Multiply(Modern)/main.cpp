#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> NormalMatrixMultiply(const vector<vector<int>> &A, const vector<vector<int>> &B);

vector<vector<int>> StrassenMatrixMultiply(const vector<vector<int>> &A, const vector<vector<int>> &B);

int main()
{
	///////////////////��ͨ�ľ���˷�///////////////////////////

	vector<vector<int>> A{ { 1,2 },{ 3,4 },{ 5,6 },{ 7,8 } };
	vector<vector<int>> B{ { 1,2,3 },{ 4,5,6 } };

	cout << "ԭʼ����A��" << endl;
	for (auto v : A)
	{
		for (auto i : v)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	cout << "ԭʼ����B��" << endl;
	for (auto v : B)
	{
		for (auto i : v)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	vector<vector<int>> C = NormalMatrixMultiply(A, B);

	cout << "����ͨ�ľ���˷��õ��ľ���A*B��" << endl;
	for (auto v : C)
	{
		for (auto i : v)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	///////////////////Strassen����˷�///////////////////////////

	vector<vector<int>> D{ { 1,3 },{ 7,5 } };
	vector<vector<int>> E{ { 6,8 },{ 4,2 } };

	cout << "ԭʼ����D��" << endl;
	for (auto v : D)
	{
		for (auto i : v)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	cout << "ԭʼ����E��" << endl;
	for (auto v : E)
	{
		for (auto i : v)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	//����֤���������˵ľ����ȷʵ�����о�Ϊn^2�ķ���


	vector<vector<int>> F = StrassenMatrixMultiply(D, E);

	cout << "��Strassen����˷��õ��ľ���D*E��" << endl;
	for (auto v : F)
	{
		for (auto i : v)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	return 0;
}

vector<vector<int>> NormalMatrixMultiply(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
	vector<vector<int>> result;
	if (A.begin()->size() == B.size())
	{
		int m = A.size();
		int n = B.size();
		int p = B.begin()->size();

		for (int i = 0; i < m; ++i)
		{
			vector<int> tempLine;
			for (int j = 0; j < p; ++j)
			{
				int sum = 0;
				for (int k = 0; k<n; ++k)
				{
					sum += A[i][k] * B[k][j];
				}
				tempLine.push_back(sum);
			}
			result.push_back(tempLine);
		}
	}
	return result;
}

vector<vector<int>> StrassenMatrixMultiply(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
	vector<vector<int>> result;
	
	//δ���

	return result;
}