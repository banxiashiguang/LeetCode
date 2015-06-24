#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr) { }
};

class Solution {
public:
	bool isSameTree(TreeNode *p,TreeNode *q) {
		if(p && q) {
			if(p->val != q->val)
				return false;
			else
				return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
		}else if(p == nullptr && q == nullptr)
			return true;
		else
			return false;
	}
};

int main(int argc,const char *argv[])
{
	return 0;
}
