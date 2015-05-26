#include <iostream>
#include <algorithm>
#include <memory>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr) { }
};

class Solution {
public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>> res;
		if(root == nullptr)
			return res;
		queue<TreeNode*> value;
		value.push(root);
		value.push(nullptr);
		vector<int> tmp;
		int isReverse = 0;
		while(value.size() > 1) {
			TreeNode *node = value.front();
			value.pop();
			if(node == nullptr) {
				value.push(nullptr);
				if(isReverse)
					reverse(tmp.begin(),tmp.end());
				isReverse ^= 1;
				res.push_back(tmp);
				tmp.clear();
			}else {
				tmp.push_back(node->val);
				if(node->left)
					value.push(node->left);
				if(node->right)
					value.push(node->right);
			}
		}
		if(isReverse)
			reverse(tmp.begin(),tmp.end());
		res.push_back(tmp);
		for(auto i:res) {
			for(auto j:i)
				cout << j << "\t";
			cout << endl;
		}
		return res;
	}
};

int main(int argc,const char *argv[]) 
{
	shared_ptr<TreeNode> root(new TreeNode(3));
	shared_ptr<TreeNode> left(new TreeNode(9));
	shared_ptr<TreeNode> right(new TreeNode(20));
	shared_ptr<TreeNode> tmp1(new TreeNode(15));
	shared_ptr<TreeNode> tmp2(new TreeNode(7));
	root->left = left.get();
	root->right = right.get();
	right->left = tmp1.get();
	right->right = tmp2.get();
	Solution s;
	s.zigzagLevelOrder(root.get());
	return 0;
}
