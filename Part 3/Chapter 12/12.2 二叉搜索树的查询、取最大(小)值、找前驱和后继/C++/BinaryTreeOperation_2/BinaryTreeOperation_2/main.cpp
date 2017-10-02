#include <iostream>

using namespace std;

struct TreeNode
{
	int key = 0;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;
	TreeNode *father = nullptr;
};

struct Tree
{
	Tree();
	~Tree();

	TreeNode *Root = nullptr;
};

Tree::Tree()
{
	Root = new TreeNode{ 4,nullptr,nullptr,nullptr };
	Root->left = new TreeNode{ 2,nullptr,nullptr,Root };
	Root->left->left = new TreeNode{ 1,nullptr,nullptr,Root->left };
	Root->left->right = new TreeNode{ 3,nullptr,nullptr,Root->left };
	Root->right = new TreeNode{ 6,nullptr,nullptr,Root };
	Root->right->left = new TreeNode{ 5,nullptr,nullptr,Root->right };
	Root->right->right = new TreeNode{ 7,nullptr,nullptr,Root->right };
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

TreeNode* TreeSearch(TreeNode *x, int key)
{
	if (x==nullptr || key==x->key)
	{
		return x;
	}
	else
	{
		if (key < x->key)
		{
			return TreeSearch(x->left,key);
		}
		else
		{
			return TreeSearch(x->right, key);
		}
	}
}

TreeNode* IterativeTreeSearch(TreeNode *x, int key)
{
	while (x!=nullptr && key!=x->key)
	{
		if (key < x->key)
		{
			x = x->left;
		}
		else { x = x->right; }
	}
	return x;
}

TreeNode* TreeMinimum(TreeNode *x)
{
	while (x->left != nullptr)
	{
		x = x->left;
	}
	return x;
}

TreeNode* TreeMaxmum(TreeNode *x)
{
	while (x->right != nullptr)
	{
		x = x->right;
	}
	return x;
}

TreeNode* TreePredecessor(TreeNode *x)
{
	if (x->left != nullptr)
	{
		return TreeMaxmum(x->left);
	}
	else
	{
		TreeNode *y = x->father;
		while (y != nullptr&&x == y->left)
		{
			x = y; y = y->father;
		}
		return y;
	}
}

TreeNode* TreeSuccessor(TreeNode *x)
{
	if (x->right != nullptr)
	{
		return TreeMinimum(x->right);
	}
	else
	{
		TreeNode *y = x->father;
		while (y != nullptr&&x == y->right)
		{
			x = y; y = y->father;
		}
		return y;
	}
}

int main()
{
	Tree Atree;
	
	cout << TreeSearch(Atree.Root, 5)->key<<endl;
	cout << IterativeTreeSearch(Atree.Root,1)->key<<endl;
	cout << TreeMaxmum(Atree.Root)->key <<endl;
	cout << TreeMinimum(Atree.Root)->key << endl;
	cout << TreePredecessor(TreeSearch(Atree.Root, 4))->key << endl;
	cout << TreeSuccessor(TreeSearch(Atree.Root, 6))->key << endl;

	return 0;
}