#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <cmath>
#include <ctime>

using namespace std;

bool isPrimeNumber(int num);
int Hash1(int key,int size);
int Hash2(int key, int size);
void UniversalHashing(list<vector<int>> &T, vector<int> &O);

int main()
{
	vector<int> temp;
	vector<int> originArr = {1,3,4,6,73,32,65,43,24,90,77};
	list<vector<int>> UniversalHashingTable(originArr.size(),temp);

	UniversalHashing(UniversalHashingTable, originArr);

	int i = 1;
	for (auto v:UniversalHashingTable)
	{
		cout << "in vector:" << i << "(level1)"<<endl;
		int j = 1;
		for (auto key:v)
		{
			cout << "key:" << key << " ";
			++j;
		}
		++i;
		cout << endl;
	}

	return 0;
}

bool isPrimeNumber(int num)
{
	if (num == 2 || num == 3)
	{
		return true;
	}
	else
	{
		for (int i = 2;num<sqrt(num);++i)
		{
			if (num%2==0)
			{
				return false;
			}
		}
		return true;
	}
}

int Hash1(int key, int size)
{
	const int m = size;

	int p = size;
	while(!isPrimeNumber(size))
	{
		++p;
	}

	uniform_int_distribution<unsigned> Za(1, p - 1);
	uniform_int_distribution<unsigned> Zb(0, p - 1);
	static default_random_engine e(time(0));

	static int a = Za(e);
	static int b = Zb(e);

	return ((a*key + b) % p) % m;
}

int Hash2(int key, int size)
{
	const int m = size;

	int p = size;
	while (!isPrimeNumber(size))
	{
		++p;
	}

	uniform_int_distribution<unsigned> Za(1, p - 1);
	uniform_int_distribution<unsigned> Zb(0, p - 1);
	static default_random_engine e(time(0));

	static int a = Za(e);
	static int b = Zb(e);

	return ((a*key + b) % p) % m;
}

void UniversalHashing(list<vector<int>> &T, vector<int> &O)
{
	for (auto key : O)
	{
		int level1HashCode = Hash1(key, O.size());
		auto l2tIter = T.begin();
		for (int i = 0; i < level1HashCode; ++i)
		{
			++l2tIter;
		}

		vector<int> &level2Table = *l2tIter;

		int level2HashCode = Hash2(key, O.size());

		if (level2HashCode >= level2Table.size())
		{
			int pownum = 2;
			while (pownum < level2HashCode + 1)
			{
				pownum *= 2;
			}
			level2Table.resize(pownum);
		}
		level2Table[level2HashCode] = key;
	}
}