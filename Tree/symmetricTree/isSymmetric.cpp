#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr) { }
};

class Solution {
public:
	bool judgement(TreeNode *pLeft,TreeNode *pRight) {
		if(pLeft && pRight) {
			if(pLeft->val != pRight->val)
				return false;
			else
				return judgement(pLeft->left,pRight->right) && judgement(pLeft->right,pRight->left);
		}else if(pLeft == nullptr && pRight == nullptr)
			return true;
		else
			return false;
	}
	bool isSymmetric(TreeNode *root) {
		if(root == nullptr || root->left == nullptr && root->right == nullptr)
			return true;
		return judgement(root->left,root->right);
	}
};

int main(int argc,const char *argv[])
{
	return 0;
}
