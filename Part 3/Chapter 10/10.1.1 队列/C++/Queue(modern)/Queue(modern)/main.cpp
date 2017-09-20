#include <iostream>
#include <queue>

using namespace std;

int main()
{
	//创建一个队列。
	queue<int> Queue;

	//测试队列是否为空
	bool b = Queue.empty();

	//入队
	Queue.push(1);

	//出队
	Queue.pop();

	return 0;
}