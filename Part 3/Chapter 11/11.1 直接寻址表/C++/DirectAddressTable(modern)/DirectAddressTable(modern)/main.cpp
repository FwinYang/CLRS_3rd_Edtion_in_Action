#include <vector>

using namespace std;

struct DirectAddressTableNode
{
	int key;
	int data;
};

struct DirectAddressTable
{
	//����һ��ֱ��Ѱַ��
	//����ȫ��Ϊ0~99
	DirectAddressTable()
	{
		DATB.resize(100,nullptr);
	}

	vector<DirectAddressTableNode*> DATB;
	
	//�ѹؼ���Ϊkey��kԪ�طŵ�ֱ��Ѱַ�����档
	void DIRECT_ADDRESS_INSERT(DirectAddressTableNode *k)
	{
		DATB[k->key] = k;
	}

	//��ֱ��Ѱַ����Ѱ��xԪ�ء�
	DirectAddressTableNode* DIRECT_ADDRESS_SEARCH(DirectAddressTableNode *x)
	{
		return DATB[x->key];
	}

	//ɾ��ֱ��ɢ�б�T�йؼ���Ϊkey��x��Ԫ�ء�
	void DIRECT_ADDRESS_DELETE(DirectAddressTableNode *x)
	{
		DATB[x->key] = nullptr;
	}
};

int main()
{
	DirectAddressTable DAT;

	//���������ڵ㡣
	DirectAddressTableNode Node1;
	Node1.key = 0;
	Node1.data = 0;

	DirectAddressTableNode Node2;
	Node2.key = 3;
	Node2.data = 3;

	//���������ڵ����ֱ��Ѱַ��
	DAT.DIRECT_ADDRESS_INSERT(&Node1);
	DAT.DIRECT_ADDRESS_INSERT(&Node2);

	//����Node1��ֱ��Ѱַ���е���Ϣ
	auto node = DAT.DIRECT_ADDRESS_SEARCH(&Node1);

	//��ֱ��Ѱַ����ɾ��Node2��
	DAT.DIRECT_ADDRESS_DELETE(&Node2);

	return 0;
}