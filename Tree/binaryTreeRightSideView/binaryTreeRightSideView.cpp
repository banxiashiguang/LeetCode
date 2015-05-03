#include <iostream>
#include <queue>
#include <vector>
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
	vector<int> rightSideView(TreeNode *root)
	{
		vector<int> res;
		if(root == nullptr)
			return res;
		queue<TreeNode *> value;
		value.push(root);
		cout << "root=" << root->val << endl;
		TreeNode *node;
		while(!value.empty())
		{
			int count = value.size();
			for(int i = 0; i < count; ++i)
			{
				cout << "i=" << i << endl;
				node = value.front();
				value.pop();
				if(node->left)
					value.push(node->left);
				if(node->right)
					value.push(node->right);
			}
			res.push_back(node->val);
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
	TreeNode *tmp = new TreeNode(2);
	TreeNode *tmp1 = new TreeNode(3);
	root->left = tmp;
	root->right = tmp1;
	Solution s;
	s.rightSideView(root);	
	delete root;
	delete tmp;
	delete tmp1;
	return 0;
}
