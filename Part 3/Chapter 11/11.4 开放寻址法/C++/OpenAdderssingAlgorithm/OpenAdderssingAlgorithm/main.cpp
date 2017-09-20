#include <iostream>
#include <vector>

using namespace std;

int hashInsert(vector<int> &T, int key);
int hashSearch(vector<int> &T, int key);

//线性探查
int h1(int key, int i, int m);
//二次探查
int h2(int key, int i, int m);
//双重散列
int h3(int key, int i, vector<int> &T);

int main()
{
	vector<int> table(600,-1);

	hashInsert(table, 28);
	int resultIndex = hashSearch(table, 28);

	return 0;
}

int hashInsert(vector<int> &T, int key)
{
	int i = 0;
	do
	{
		int j = h1(key, i, T.size());
		if (T[j] == -1)
		{
			T[j] = key;
			return j;
		}
		else ++i;
	} while (i == T.size()-1);
	return -1;
}

int hashSearch(vector<int> &T, int key)
{
	int i = 0, j = 0;
	do
	{
		j = h1(key, i, T.size());
		if (T[j] == key)
		{
			return j;
		}
		++i;
	} while (T[j] == -1 || i == T.size() - 1);
	return -1;
}

int h1(int key, int i, int m)
{
	return (key%m + i) % m;
}

int h2(int key, int i, int m)
{
	return (key%m + i*29+ i*i*37) % m;
}

int h3(int key, int i, vector<int> &T)
{
	int m = T.size();
	int n = 1;
	for (;m>n;n*=2){}
	T.insert(T.end(),n-m,-1);

	int result = (key * 3 % m + i*key % (m - 1));
	if (result % 2 == 0){ return --result; }
	else{ return result; }
}