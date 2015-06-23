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
	int minDepth(TreeNode *root) {
		if(root == nullptr)
			return 0;
		int len1 = minDepth(root->left);
		int len2 = minDepth(root->right);
		if(len1 > 0 && len2 > 0)
			return len1 < len2? len1+1:len2+1;
		else
			return len1 == 0? len2+1:len1+1;
	}
};

int main(int argc,const char *argv[])
{
	shared_ptr<TreeNode> root(new TreeNode(1));
	shared_ptr<TreeNode> left(new TreeNode(2));
	root->left = left.get();
	Solution s;
	cout << s.minDepth(root.get()) << endl;
	return 0;
}
