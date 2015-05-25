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
	TreeNode* buildChildTree(vector<int> &inorder,int iL,int iR,vector<int> &postorder,int pL,int pR) {
		if(iL >= iR)
			return nullptr;
		TreeNode *root = new TreeNode(postorder[pR-1]);
		int i{0};
		for(i = iL; i != iR; ++i)
			if(postorder[pR-1] == inorder[i])
				break;
		root->left = buildChildTree(inorder,iL,i,postorder,pL,pL+i-iL);
		root->right = buildChildTree(inorder,i+1,iR,postorder,pL+i-iL,pR-1);
		return root;
	}
	TreeNode* buildTree(vector<int> &inorder,vector<int> &postorder) {
		if(inorder.size() == 1)
			return nullptr;
		return buildChildTree(inorder,0,inorder.size(),postorder,0,postorder.size());
	}
};

void postOrder(TreeNode *root) {
	if(root == nullptr)
		return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->val << "\t";
}
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
		vector<int> inorder{4,2,5,1,3};
		vector<int> postorder{4,5,2,3,1};
		TreeNode *root = s.buildTree(inorder,postorder);
		postOrder(root);
		cout << endl;
		inOrder(root);
		cout << endl;
		preOrder(root);
		cout << endl;
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
