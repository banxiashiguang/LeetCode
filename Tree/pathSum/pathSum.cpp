#include <iostream>
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
	bool hasPathSum(TreeNode *root,int sum) {
		if(root == nullptr)
			return false;
		sum -= root->val;
		if(root->left == nullptr && root->right == nullptr) {
			if(sum == 0)
				return true;
			else
				return false;
		}
		return hasPathSum(root->left,sum) || hasPathSum(root->right,sum);
	}
	/*bool hasPathSum(TreeNode *root,int sum) {
		if(root == nullptr)
			return false;
		stack<TreeNode*> node;
		node.push(root);
		stack<int> tValue;
		tValue.push(root->val);
		while(!node.empty()) {
			TreeNode *tmp = node.top();
			node.pop();
			int value = tValue.top();
			tValue.pop();
			if(value == sum) {
				if(tmp->left == nullptr && tmp->right == nullptr)
					return true;
			}
			if(tmp->right) {
				node.push(tmp->right);
				tValue.push(value+tmp->right->val);
			}
			if(tmp->left) {
				node.push(tmp->left);
				tValue.push(value+tmp->left->val);
			}
		}
	}*/
};

int main(int argc,const char *argv[])
{
	return 0;
}
