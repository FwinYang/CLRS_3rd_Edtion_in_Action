#include <iostream>
#include <queue>

using namespace std;

int main()
{
	//����һ�����С�
	queue<int> Queue;

	//���Զ����Ƿ�Ϊ��
	bool b = Queue.empty();

	//���
	Queue.push(1);

	//����
	Queue.pop();

	return 0;
}