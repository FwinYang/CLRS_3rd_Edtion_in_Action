#include <memory>

using namespace std;

struct TreeNode
{
	int val = 0;

	shared_ptr<TreeNode> p = nullptr;
	shared_ptr<TreeNode> left = nullptr;
	shared_ptr<TreeNode> right = nullptr;
};

struct Tree
{
	shared_ptr<TreeNode> root = nullptr;
};

int main()
{
	Tree tree;

	return 0;
}