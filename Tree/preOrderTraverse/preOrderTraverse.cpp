#include <iostream>
#include <stack>
#include <iostream>
#include <memory>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr) { }
};

//前序的递归遍历
void recursivePreOrderTraverse(TreeNode *root)
{
	if(root == nullptr)
		return;
	cout << root->val<< "\t";
	recursivePreOrderTraverse(root->left);
	recursivePreOrderTraverse(root->right);
}

void noRecPreOrderTraverse(TreeNode *root)
{
	if(root == nullptr)
		return;
	stack<TreeNode *> value;
	value.push(root);
	while(!value.empty())
	{
		TreeNode *node = value.top();
		value.pop();
		cout << node->val << "\t";
		if(node->right)
			value.push(node->right);
		if(node->left)
			value.push(node->left);
	}
}

int main(int argc,const char *argv[])
{
	shared_ptr<TreeNode> root(new TreeNode(1));
	shared_ptr<TreeNode> left(new TreeNode(2));
	shared_ptr<TreeNode> right(new TreeNode(3));
	shared_ptr<TreeNode> tmp1(new TreeNode(4));
	shared_ptr<TreeNode> tmp2(new TreeNode(5));
	shared_ptr<TreeNode> tmp3(new TreeNode(6));
	root->left = left.get();
	root->right = right.get();
	left->left = tmp1.get();
	right->left = tmp2.get();
	right->right = tmp3.get();
	cout << "递归" << endl;
	recursivePreOrderTraverse(root.get());
	cout << endl;
	cout << "非递归" << endl;
	noRecPreOrderTraverse(root.get());
	cout << endl;
	return 0;
}
