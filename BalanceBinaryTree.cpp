#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL) { }
};

class BalanceBinaryTree
{
public:
	BalanceBinaryTree() { }
	~BalanceBinaryTree() { }

	/**
	 * 改进前方法：
	 * 平衡二叉树当前节点的高度：左、右子树最大高度加1
	 */
	int getDepth(TreeNode *root)
	{
		if(root == NULL)
			return 0;
		return max(getDepth(root->left),getDepth(root->right))+1;
	}

	/**
	 * 存在问题：在比较过程中，总是从上到下比较，在求当前节点的高度时
	 * 下方的节点总是遍历多次。
	 * 解决方法：在求高度时，进行判断。
	 */
	
	bool childBalanced(TreeNode *root,int &depth)
	{
		if(root == NULL)
		{
			depth = 0;
			return true;
		}
		int left = 0;
		int right = 0;
		if(childBalanced(root->left, left) && childBalanced(root->right, right))
		{
			if(abs(left-right) > 1)
				return false;
			depth = left > right? left+1:right+1;
			return true;
		}
	}
	
	bool isBalanced(TreeNode *root)
	{
		if(root == NULL)
			return true;
		/*int left = getDepth(root->left);
		int right = getDepth(root->right);
		int diff = left - right;
		if(diff >= -1 && diff <= 1)
		{
			return isBalanced(root->left) && isBalanced(root->right);
		}else{
			return false;
		}*/
		int depth = 0;
		return childBalanced(root, depth);
	}
};

int main(int argc, char const *argv[])
{
	TreeNode *root = new TreeNode(1);
	TreeNode *left = new TreeNode(2);
	TreeNode *right = new TreeNode(3);
	TreeNode *tmp1 = new TreeNode(4);
	TreeNode *tmp2 = new TreeNode(5);
	root->left = left;
	root->right = right;
	left->left = tmp1;
	tmp1->left = tmp2;
	BalanceBinaryTree b;
	cout << b.isBalanced(root) << endl;
	delete root;
	delete left;
	delete right;
	delete tmp1;
	delete tmp2;
	return 0;
}