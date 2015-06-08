#include <iostream>
#include <memory>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr) { }
};

class Solution {
public:
	int maxDepth(TreeNode *root) {
		if(root == nullptr)
			return 0;
		int pL = maxDepth(root->left);
		int pR = maxDepth(root->right);
		return max(pL,pR)+1;
	}
};

int main(int argc,const char *arv[])
{
	shared_ptr<TreeNode> root(new TreeNode(1));
	shared_ptr<TreeNode> left(new TreeNode(2));
	shared_ptr<TreeNode> right(new TreeNode(3));
	shared_ptr<TreeNode> tmp(new TreeNode(4));
	root->left = left.get();
	root->right = right.get();
	left->left = tmp.get();
	Solution s;
	cout << s.maxDepth(root.get()) << endl;	
	return 0;
}
