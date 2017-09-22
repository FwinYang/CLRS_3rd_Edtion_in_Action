#include <iostream>

using namespace std;

struct TreeNode
{
	int key = 0;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;
};

struct Tree
{
	Tree();
	~Tree();
	
	void FTreeWalk(TreeNode *n);
	void MTreeWalk(TreeNode *n);
	void LTreeWalk(TreeNode *n);

	TreeNode *Root = nullptr;
};

Tree::Tree()
{
	Root = new TreeNode{ 4,nullptr,nullptr };
	Root->left = new TreeNode{ 3,nullptr,nullptr };
	Root->left->left = new TreeNode{ 1,nullptr,nullptr };
	Root->left->right = new TreeNode{ 2,nullptr,nullptr };
	Root->right = new TreeNode{ 5,nullptr,nullptr };
	Root->right->left = new TreeNode{ 6,nullptr,nullptr };
	Root->right->right = new TreeNode{ 7,nullptr,nullptr };
}

Tree::~Tree()
{
	delete Root->left->left;
	delete Root->left->right;
	delete Root->left;
	delete Root->right->left;
	delete Root->right->right;
	delete Root->right;
	delete Root;
}

void Tree::FTreeWalk(TreeNode *n)
{
	if (n!=nullptr)
	{
		cout << n->key << " ";
		FTreeWalk(n->left);
		FTreeWalk(n->right);
	}
}

void Tree::MTreeWalk(TreeNode *n)
{
	if (n != nullptr)
	{	
		MTreeWalk(n->left);
		cout << n->key << " ";
		MTreeWalk(n->right);
	}
}

void Tree::LTreeWalk(TreeNode *n)
{
	if (n != nullptr)
	{
		LTreeWalk(n->left);
		LTreeWalk(n->right);
		cout << n->key << " ";
	}
}

int main()
{
	Tree Atree;
	cout << "先序遍历: ";
	Atree.FTreeWalk(Atree.Root);
	cout << "\n中序遍历: ";
	Atree.MTreeWalk(Atree.Root);
	cout << "\n后序遍历: ";
	Atree.LTreeWalk(Atree.Root);

	return 0;
}