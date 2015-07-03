#include <iostream>
#include <vector>
#include <stack>
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
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> res;
		if(root == nullptr)
			return res;
		stack<TreeNode*> value;
		value.push(root);
		while(!value.empty()) {
			TreeNode *node = value.top();
			value.pop();
			res.push_back(node->val);
			if(node->right)
				value.push(node->right);
			if(node->left)
				value.push(node->left);
		}
		for(auto i:res)
			cout << i << "\t";
		cout << endl;
		return res;
	}
};

void recursivePreorder(TreeNode *root,vector<int> &res) {
	if(root == nullptr)
		return;
	res.push_back(root->val);
	recursivePreorder(root->left,res);
	recursivePreorder(root->right,res);
}

int main(int argc,const char *argv[])
{
	shared_ptr<TreeNode> root(new TreeNode(1));
	shared_ptr<TreeNode> left(new TreeNode(2));
	shared_ptr<TreeNode> right(new TreeNode(3));
	root->left = left.get();
	root->right = right.get();
	Solution s;
	s.preorderTraversal(root.get());
	vector<int> res;
	recursivePreorder(root.get(),res);
	for(auto i:res)
		cout << i << "\t";
	cout << endl;
	return 0;
}
