#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
	//创建一个链表L
	list<int> L{1,2,3,4,5};

	//搜索并返回值链表中值为3的元素的迭代器
	auto result = find(L.begin(), L.end(), 3);

	//插入6到链表首
	L.push_front(6);

	//删除第迭代器i指向的元素
	auto i = find(L.begin(), L.end(), 4);
	L.erase(i);

	return 0;
}