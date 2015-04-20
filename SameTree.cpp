#include <iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL) { }
};

class SameTree
{
public:
	SameTree() { }
	~SameTree() { }
	bool isSameTree(TreeNode *p,TreeNode *q)
	{
		if(p != NULL && q != NULL)
		{
			if(p->val != q->val)
				return false;
			if(isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
				return true;
		}else if(p != NULL && q == NULL || p == NULL && q != NULL)
			return false;
		else
			return true;
	}
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}