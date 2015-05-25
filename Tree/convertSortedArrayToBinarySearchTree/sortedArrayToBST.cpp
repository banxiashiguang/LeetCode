#include <iostream>
#include <stack>
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
	TreeNode *buildBST(vector<int> &nums,int left,int right) {
		if(left > right)
			return nullptr;
		int mid = (left+right)>>1;
		TreeNode *root = new TreeNode(nums[mid]);
		root->left = buildBST(nums,left,mid-1);
		root->right = buildBST(nums,mid+1,right);
		return root;
	}
	TreeNode *sortedArrayToBST(vector<int> &nums) {
		if(nums.size() ==  0)
			return nullptr;
		return buildBST(nums,0,nums.size()-1);
	}
};

void inOrder(TreeNode *root) {
	if(root == nullptr)
		return;
	inOrder(root->left);
	cout << root->val << "\t";
	inOrder(root->right);
}

int main(int argc,const char *argv[])
{
	vector<int> nums{1,2,3,4,5,6};
	Solution s;
	TreeNode *root = s.sortedArrayToBST(nums);
	inOrder(root);
	stack<TreeNode*> value;
	value.push(root);
	while(!value.empty()) {
		TreeNode *node = value.top();
		value.pop();
		if(node->left)
			value.push(node->left);
		if(node->right)
			value.push(node->right);
		delete node;
	}
	return 0;
}
