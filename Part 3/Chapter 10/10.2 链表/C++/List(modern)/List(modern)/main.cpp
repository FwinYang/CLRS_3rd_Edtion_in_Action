#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
	//����һ������L
	list<int> L{1,2,3,4,5};

	//����������ֵ������ֵΪ3��Ԫ�صĵ�����
	auto result = find(L.begin(), L.end(), 3);

	//����6��������
	L.push_front(6);

	//ɾ���ڵ�����iָ���Ԫ��
	auto i = find(L.begin(), L.end(), 4);
	L.erase(i);

	return 0;
}