#include <vector>
#include <list>

using namespace std;

const int Usize = 100;

struct tableNode
{
	int key;
	int data;
};

struct ChainedHashTable
{
	ChainedHashTable()
	{
		hashBase.resize(100);
	}


	void CHAINED_HASH_INSERT(tableNode t)
	{
		hashBase[h(t.key)].push_front(t);
	}

	tableNode CHAINED_HASH_SEARCH(int k)
	{
		for (auto e : hashBase[h(k)])
		{
			if (e.key == k)
			{
				return e;
			}
		}
	}

	void CHAINED_HASH_DELETE(int k)
	{
		for (auto e = hashBase[h(k)].begin();e!= hashBase[h(k)].end();++e)
		{
			if (e->key == k)
			{
				hashBase[h(k)].erase(e);
				break;
			}
		}
	}

	int h(int k) { return k / 4; }

	vector<list<tableNode>> hashBase;
};

int main()
{
	//����һ�����ӷ���ϣ��
	ChainedHashTable CHT;

	//����һЩԪ�ء�
	tableNode N1{ 0,0 };
	tableNode N2{ 1,1 };
	tableNode N3{ 2,2 };
	tableNode N4{ 4,4 };
	tableNode N5{ 10,10 };

	//�����ϣ��
	CHT.CHAINED_HASH_INSERT(N1);
	CHT.CHAINED_HASH_INSERT(N2);
	CHT.CHAINED_HASH_INSERT(N3);
	CHT.CHAINED_HASH_INSERT(N4);
	CHT.CHAINED_HASH_INSERT(N5);

	//������ֵΪ1��4��Ԫ��
	auto nv2 = CHT.CHAINED_HASH_SEARCH(1);
	auto nv10 = CHT.CHAINED_HASH_SEARCH(4);

	//ɾ����ֵΪ2��10��Ԫ��
	CHT.CHAINED_HASH_DELETE(2);
	CHT.CHAINED_HASH_DELETE(10);

	return 0;
}