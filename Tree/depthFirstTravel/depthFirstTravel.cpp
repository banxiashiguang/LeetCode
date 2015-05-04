#include <iostream>
#include <vector>
#include <stack>
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
	vector<int> depthFirstTravel(TreeNode *root)
	{
		cout << "depthFirstTravel" << endl;
		vector<int> res;
		if(root == nullptr)
			return res;
		stack<TreeNode *> value;
		value.push(root);
		TreeNode *node = nullptr;
		while(!value.empty())
		{
			node = value.top();
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

int main(int argc,const char *argv[])
{
	TreeNode *root = new TreeNode(1);
	TreeNode *left = new TreeNode(2);
	TreeNode *right = new TreeNode(3);
	TreeNode *tmp = new TreeNode(4);
	root->left = left;
	root->right = right;
	left->right = tmp;
	Solution s;
	s.depthFirstTravel(root);
	return 0;
}
