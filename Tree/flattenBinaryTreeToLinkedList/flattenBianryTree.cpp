#include <iostream>
#include <memory>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr) { }
};

class Solution {
public:
	void flatten(TreeNode *root) {
		if(root == nullptr)
			return;
		stack<TreeNode*> value;
		value.push(root);
		TreeNode *p = nullptr;
		while(!value.empty()) {
			TreeNode *node = value.top();
			value.pop();
			cout << node->val << "\t";
			if(node->right)
				value.push(node->right);
			if(node->left)
				value.push(node->left);
			node->left = nullptr;
			if(p == nullptr)
				p = node;
			else{
				p->right = node;
				p = p->right;
			}
		}
	}
};

int main(int argc,const char *argv[])
{
	unique_ptr<TreeNode> root(new TreeNode(1));
	unique_ptr<TreeNode> left(new TreeNode(2));
	unique_ptr<TreeNode> right(new TreeNode(5));
	unique_ptr<TreeNode> ll(new TreeNode(3));
	unique_ptr<TreeNode> lr(new TreeNode(4));
	root->left = left.get();
	root->right = right.get();
	left->left = ll.get();
	left->right = lr.get();
	Solution s;
	s.flatten(root.get());
	return 0;
}
