#include <iostream>
#include <utility>
#include <memory>
#include <stack>
#include <vector>
#include <string>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr) { }
};

class Solution
{
public:
	int sumNumbers(TreeNode *root)
	{
		if(root == nullptr)
			return 0;
		int sum = 0;
		stack<TreeNode *> node;
		stack<int> value;
		node.push(root);
		value.push(root->val);
		while(!node.empty())
		{
			auto iter1 = node.top();
			auto iter2 = value.top();
			node.pop();
			value.pop();
			if(iter1->left == nullptr && iter1->right == nullptr)
				sum += iter2; 
			if(iter1->right)
			{
				node.push(iter1->right);
				value.push(iter2*10 + iter1->right->val);
			}
			if(iter1->left)
			{
				node.push(iter1->left);
				value.push(iter2*10 + iter1->left->val);
			}
		}
		return sum;
	}
};

int main(int argc,const char *argv[])
{
	shared_ptr<TreeNode> root(new TreeNode(1));
	shared_ptr<TreeNode> left(new TreeNode(2));
	shared_ptr<TreeNode> right(new TreeNode(3));
	root->left = left.get();
	root->right = right.get();
	Solution s;
	cout << s.sumNumbers(root.get()) << endl;
	return 0;
}
