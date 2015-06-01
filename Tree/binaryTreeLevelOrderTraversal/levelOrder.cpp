#include <iostream>
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
	vector<vector<int>> levelOrder(TreeNode *root) {
		vector<vector<int>> res;
		if(root == nullptr)
			return res;
		queue<TreeNode*> value;
		value.push(root);
		value.push(nullptr);
		vector<int> tmp;
		while(value.size() > 1) {
			TreeNode *node = value.front();
			value.pop();
			if(node == nullptr) {
				value.push(nullptr);
				res.push_back(tmp);
				tmp.clear();
			}else{
				tmp.push_back(node->val);
				if(node->left)
					value.push(node->left);
				if(node->right)
					value.push(node->right);
			}
		}
		res.push_back(tmp);
		return res;
	}
};


int main(int argc,const char *argv[]) 
{
	shared_ptr<TreeNode> root(new TreeNode(3));
	shared_ptr<TreeNode> left(new TreeNode(9));
	shared_ptr<TreeNode> right(new TreeNode(20));
	root->left = left.get();
	root->right = right.get();
	Solution s;
	vector<vector<int>> res = s.levelOrder(root.get());
	for(auto i:res) {
		for(auto j:i)
			cout << j << "\t";
		cout << endl;
	}
	return 0;
}
