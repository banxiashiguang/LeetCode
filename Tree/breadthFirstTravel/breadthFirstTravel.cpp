#include <iostream>
#include <vector>
#include <queue>
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
	vector<vector<int> > breadthFirstTravel(TreeNode *root)
	{
		vector<vector<int> > res;
		if(root == nullptr)
			return res;
		vector<int> tmp;
		queue<TreeNode *> value;
		value.push(root);
		value.push(nullptr);
		while(value.size() > 1)
		{
			TreeNode *node = value.front();
			value.pop();
			if(node == nullptr)
			{
				value.push(nullptr);
				res.push_back(tmp);
				tmp.clear();
				continue;
			}
			tmp.push_back(node->val);
			if(node->left)
				value.push(node->left);
			if(node->right)
				value.push(node->right);
		}
		res.push_back(tmp);
		for(auto i:res)
		{
			for(auto j:i)
				cout << j << "\t";
			cout << endl;
		}
		return res;
	}
};

int main(int argc,const char *argv[])
{
	Solution s;
	TreeNode *root = new TreeNode(1);
	TreeNode *left = new TreeNode(2);
	TreeNode *right = new TreeNode(3);
	root->left = left;
	root->right = right;
	s.breadthFirstTravel(root);
	delete root;
	delete left;
	delete right;
	return 0;
}
