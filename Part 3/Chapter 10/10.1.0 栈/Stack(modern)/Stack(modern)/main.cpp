#include <iostream>
#include <stack>

using namespace std;

int main()
{
	//����һ��ջ��
	stack<int> Stack;

	//�����Ƿ�Ϊ��
	bool b = Stack.empty();

	//��ջ
	Stack.push(1);

	//��ջ
	Stack.pop();

	return 0;
}