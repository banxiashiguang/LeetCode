#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL) { }
};

class PathSum
{
public:
	PathSum() { }
	~PathSum() { }

	bool hasPathSum(TreeNode *root,int sum)
	{
		if(root == NULL)
			return false;
		if(root->left == NULL && root->right == NULL)
			return root->val == sum? true:false;
		else
		{
			if(hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val))
				return true;
			else
				return false;
		}
	}
};

int main(int argc, char const *argv[])
{
	TreeNode *root = new TreeNode(2);
	TreeNode *left = new TreeNode(3);
	TreeNode *right = new TreeNode(1);
	TreeNode *tmp = new TreeNode(4);
	TreeNode *tmp1 = new TreeNode(5);
	root->left = left;
	root->right = right;
	left->left = tmp;
	left->right = tmp1;
	PathSum p;
	cout << p.hasPathSum(root, 100) << endl;
	delete root;
	delete left;
	delete right;
	delete tmp;
	delete tmp1;
	return 0;
}