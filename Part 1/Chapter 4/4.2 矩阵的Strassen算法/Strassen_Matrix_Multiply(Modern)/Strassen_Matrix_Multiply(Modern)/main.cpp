#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> NormalMatrixMultiply(const vector<vector<int>> &A, const vector<vector<int>> &B);

vector<vector<int>> StrassenMatrixMultiply(const vector<vector<int>> &A, const vector<vector<int>> &B);

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

	vector<vector<int>> D{ { 1,3 },{ 7,5 } };
	vector<vector<int>> E{ { 6,8 },{ 4,2 } };

	cout << "原始矩阵D：" << endl;
	for (auto v : D)
	{
		for (auto i : v)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	cout << "原始矩阵E：" << endl;
	for (auto v : E)
	{
		for (auto i : v)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	//现验证这两个被乘的矩阵的确实是行列均为n^2的方阵。


	vector<vector<int>> F = StrassenMatrixMultiply(D, E);

	cout << "用Strassen方阵乘法得到的矩阵D*E：" << endl;
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
	
	//未完成

	return result;
}