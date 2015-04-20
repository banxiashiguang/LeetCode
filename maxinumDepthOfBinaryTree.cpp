#include <iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL) { }
};

class maxinumDepthOfBinaryTree
{
public:
	maxinumDepthOfBinaryTree() { }
	~maxinumDepthOfBinaryTree() { }
	int getDepth(TreeNode *root)
	{
		if(root == NULL)
			return 0;
		return max(getDepth(root->left),getDepth(root->right))+1;
	}

	int maxDepth(TreeNode *root)
	{
		if(root == NULL)
			return 0;
		int res = getDepth(root);
		return res;
	}
};

int main(int argc, char const *argv[])
{
	TreeNode *root = new TreeNode(1);
	TreeNode *left = new TreeNode(2);
	TreeNode *right = new TreeNode(3);
	TreeNode *tmp1 = new TreeNode(4);
	TreeNode *tmp2 = new TreeNode(5);
	//root->left = left;
	//root->right = right;
	//left->left = tmp1;
	//tmp1->left = tmp2;
	maxinumDepthOfBinaryTree m;
	cout << m.maxDepth(root) << endl;
	delete root;
	delete left;
	delete right;
	delete tmp1;
	delete tmp2;
	return 0;
}