#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr) { }
};

class Solution {
private:
	vector<vector<int>> res;
	vector<int> tmp;
public:
	vector<vector<int>> pathSum(TreeNode *root,int sum) {
		if(root == nullptr)
			return res;
		dfs(root,sum);
		return res;
	}
	void dfs(TreeNode *root,int sum) {
		if(root == nullptr)
			return;
		sum -= root->val;
		tmp.push_back(root->val);
		if(root->left == nullptr && root->right == nullptr) {
			if(sum == 0)
				res.push_back(tmp);
		}else{
			dfs(root->left,sum);
			dfs(root->right,sum);
		}
		tmp.pop_back();
	}
};

int main(int argc,const char *argv[])
{
	return 0;
}
