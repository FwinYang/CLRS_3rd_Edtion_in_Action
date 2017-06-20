#include <iostream>

using namespace std;

struct ListNode
{
	ListNode *prev = nullptr;
	ListNode *next = nullptr;

	int key = 0;
};

struct List
{
	~List()
	{
		ListNode *tempNext = nullptr;
		for (auto nowIter = head; nowIter!=nullptr;nowIter = tempNext)
		{
			tempNext = nowIter->next;
			delete nowIter;
		}
	}

	int LIST_SEARCH(int skey)
	{
		int i = 0;
		for (auto nowIter = head; nowIter != nullptr; nowIter = nowIter->next,++i)
		{
			if (nowIter->key == skey)
			{
				break;
			}
		}
		return i;
	}

	void LIST_INSERT(int skey)
	{
		auto keyPtr = new ListNode;
		keyPtr->key = skey;

		if (head != nullptr)
		{
			head->prev = keyPtr;
			keyPtr->next = head;
		}
		head = keyPtr;
	}

	void LIST_DELETE(int skey)
	{
		ListNode *nowIter = head;
		for (int i=0;i<skey-1;++i)
		{
			nowIter = nowIter->next;
		}

		if (nowIter->prev != nullptr&&nowIter->next!=nullptr)
		{
			nowIter->prev->next = nowIter->next;
			nowIter->next->prev = nowIter->prev;
		}
		else if (nowIter->prev == nullptr && nowIter->next != nullptr)
		{
			nowIter->next->prev = nullptr;
		}
		else if (nowIter->prev != nullptr && nowIter->next == nullptr)
		{
			nowIter->prev->next = nullptr;
		}
		else
		{
			head = nullptr;
		}

		delete nowIter;
	}

	ListNode *head = nullptr;
};

int main()
{
	//����һ������L
	List L;
	
	//���ΰ�6~1����������
	for (int i = 6; i >=1 ;--i)
	{
		L.LIST_INSERT(i);
	}

	//����������ֵ������ֵΪ3��Ԫ�ص�λ��
	auto index = L.LIST_SEARCH(3);

	//ɾ����3��Ԫ��
	L.LIST_DELETE(3);

	return 0;
}