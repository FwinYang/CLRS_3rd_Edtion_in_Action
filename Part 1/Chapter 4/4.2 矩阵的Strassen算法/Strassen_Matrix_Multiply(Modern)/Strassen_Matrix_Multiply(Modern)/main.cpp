#include <vector>
#include "StrassenCore.h"

using namespace std;

vector<vector<int>> NormalMatrixMultiply(const vector<vector<int>> &A, const vector<vector<int>> &B);

int main()
{
	///////////////////普通的矩阵乘法///////////////////////////

	vector<vector<int>> A{ { 1,2 },{ 3,4 },{ 5,6 },{ 7,8 } };
	vector<vector<int>> B{ { 1,2,3 },{ 4,5,6 } };

	cout << "原始矩阵A：" << endl;
	for (auto v : A)
	{
		for (auto i : v)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	cout << "原始矩阵B：" << endl;
	for (auto v : B)
	{
		for (auto i : v)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	vector<vector<int>> C = NormalMatrixMultiply(A, B);

	cout << "用普通的矩阵乘法得到的矩阵A*B：" << endl;
	for (auto v : C)
	{
		for (auto i : v)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	///////////////////Strassen方阵乘法///////////////////////////

	Strassen();

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