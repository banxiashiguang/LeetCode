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
public:
	vector<TreeNode*> dfs(int start,int end) {
		vector<TreeNode*> ret;
		if(start > end)
			return ret;
		for(int i = start; i <= end; ++i) {
			vector<TreeNode*> left = dfs(start,i-1);
			vector<TreeNode*> right = dfs(i+1,end);
			for(int j = 0; j < left.size(); ++j) {
				for(int k = 0; k < right.size(); ++k) {
					TreeNode *root = new TreeNode(i);
					ret.push_back(root);
					root->left = left[j];
					root->right = right[k];
				}
			}
		}
		return ret;
	}
	vector<TreeNode*> generateTrees(int n) {
		return dfs(1,n);
	}
};

int main(int argc,const char *argv[]) {
	Solution s;
	return 0;
}
