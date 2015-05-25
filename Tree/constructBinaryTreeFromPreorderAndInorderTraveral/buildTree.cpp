#include <iostream>
#include <stack>
#include <algorithm>
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
	TreeNode* buildChildTree(vector<int> &preorder,vector<int> &inorder,int pL,int pR,int iL,int iR) {
		if(pL == pR)
			return nullptr;
		TreeNode *root = new TreeNode(preorder[pL]);
		int i{0};
		for(i = iL; i != iR; ++i)
			if(inorder[i] == preorder[pL])
				break;
		root->left = buildChildTree(preorder,inorder,pL+1,pL+1+i-iL,iL,i);
		root->right = buildChildTree(preorder,inorder,pL+1+i-iL,pR,i+1,iR);
		return root;
	}
	TreeNode* buildTree(vector<int> &preorder,vector<int> &inorder) {
		if(preorder.size() == 0)
			return nullptr;
		return buildChildTree(preorder,inorder,0,preorder.size(),0,inorder.size());
	}
};

void preOrder(TreeNode *root) {
	if(root == nullptr)
		return;
	cout << root->val << "\t";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(TreeNode *root) {
	if(root == nullptr)
		return;
	inOrder(root->left);
	cout << root->val << "\t";
	inOrder(root->right);
}

int main(int argc,const char *argv[])
{
	Solution s;
	vector<int> preorder{1,2,4,5,3};
	vector<int> inorder{4,2,5,1,3};
	TreeNode *root = s.buildTree(preorder,inorder);
	preOrder(root);
	cout << endl;
	inOrder(root);
	stack<TreeNode*> value;
	value.push(root);
	//释放内存
	while(!value.empty()) {
		TreeNode *tmp = value.top();
		value.pop();
		if(tmp->left)
			value.push(tmp->left);
		if(tmp->right)
			value.push(tmp->right);
		delete tmp;
	}
	return 0;
}
