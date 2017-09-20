#include <vector>

using namespace std;

struct DirectAddressTableNode
{
	int key;
	int data;
};

struct DirectAddressTable
{
	//创建一个直接寻址表
	//假设全域为0~99
	DirectAddressTable()
	{
		DATB.resize(100,nullptr);
	}

	vector<DirectAddressTableNode*> DATB;
	
	//把关键字为key的k元素放到直接寻址表里面。
	void DIRECT_ADDRESS_INSERT(DirectAddressTableNode *k)
	{
		DATB[k->key] = k;
	}

	//在直接寻址表中寻找x元素。
	DirectAddressTableNode* DIRECT_ADDRESS_SEARCH(DirectAddressTableNode *x)
	{
		return DATB[x->key];
	}

	//删除直接散列表T中关键字为key的x的元素。
	void DIRECT_ADDRESS_DELETE(DirectAddressTableNode *x)
	{
		DATB[x->key] = nullptr;
	}
};

int main()
{
	DirectAddressTable DAT;

	//构建两个节点。
	DirectAddressTableNode Node1;
	Node1.key = 0;
	Node1.data = 0;

	DirectAddressTableNode Node2;
	Node2.key = 3;
	Node2.data = 3;

	//把这两个节点加入直接寻址表
	DAT.DIRECT_ADDRESS_INSERT(&Node1);
	DAT.DIRECT_ADDRESS_INSERT(&Node2);

	//搜索Node1在直接寻址表中的信息
	auto node = DAT.DIRECT_ADDRESS_SEARCH(&Node1);

	//在直接寻址表中删除Node2。
	DAT.DIRECT_ADDRESS_DELETE(&Node2);

	return 0;
}