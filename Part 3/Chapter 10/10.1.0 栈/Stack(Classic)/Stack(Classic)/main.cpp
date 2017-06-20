#include <iostream>

using namespace std;

const int StackMax = 10;

struct Stack
{
	bool Stack_Empty()
	{
		if (S_top == -1) return true;
		else return false;
	}

	void push(int x)
	{
		if (S_top != StackMax-1) {
			++S_top;
			StackBase[S_top] = x;
		}
	}

	int pop()
	{
		if (!Stack_Empty()) {
			--S_top;
			return StackBase[S_top + 1];
		}
	}

	int StackBase[StackMax] = {0};
	int S_top = -1;
};

int main()
{
	//创建一个栈。
	Stack stack;

	//测试是否为空
	bool b = stack.Stack_Empty();

	//入栈
	stack.push(1);

	//出栈
	stack.pop();

	return 0;
}