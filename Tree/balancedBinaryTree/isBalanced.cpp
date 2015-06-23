#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr) { }
};

class Solution {
public:
	int getDepth(TreeNode *root) {
		if(root == nullptr)
			return 0;
		int len1 = getDepth(root->left);
		int len2 = getDepth(root->right);
		return max(len1,len2)+1;
	}
	bool isBalanced(TreeNode *root) {
		if(root == nullptr)
			return true;
		if(abs(getDepth(root->left)-getDepth(root->right)) > 1)
			return false;
		return isBalanced(root->left) && isBalanced(root->right);
	}
};

int main(int argc,const char *argv[])
{
	return 0;
}
