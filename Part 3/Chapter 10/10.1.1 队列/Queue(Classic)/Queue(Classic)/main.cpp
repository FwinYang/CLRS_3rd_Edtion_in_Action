#include <iostream>

using namespace std;

const int QueueMax = 10;

struct Queue
{
	void ENQUEUE(int x)
	{
		int QTailNext = 0;
		tail == QueueMax - 1 ? QTailNext = 1: QTailNext = tail + 1;
		if (QTailNext!=head)
		{
			Queuebase[tail] = x;
			if (tail == QueueMax - 1) tail = 1;
			else ++tail;
		}
	}

	int DEQUEUE()
	{
		int result = 0;
		if (head!=tail)
		{
			result = Queuebase[head];
			if (head == QueueMax) head = 1;
			else ++head;
		}
		return result;
	}

	int Queuebase[QueueMax] = {0};
	int head = 0, tail = 0;
};

int main()
{
	//创建一个队列。
	Queue queue;

	//入队列
	queue.ENQUEUE(1);

	//出队列
	queue.DEQUEUE();

	return 0;
}