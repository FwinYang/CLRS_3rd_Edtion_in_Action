#include <iostream>
#include <stack>

using namespace std;

int main()
{
	//创建一个栈。
	stack<int> Stack;

	//测试是否为空
	bool b = Stack.empty();

	//入栈
	Stack.push(1);

	//出栈
	Stack.pop();

	return 0;
}