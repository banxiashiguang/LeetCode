#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL) { }
};
class SymmetricTree
{
public:
	SymmetricTree() { }
	~SymmetricTree() { }

	/**
	 * 解题思路：
	 * @param  node1 [description]
	 * @param  node2 [description]
	 * @return       [description]
	 */
	bool solution(TreeNode *node1,TreeNode *node2)
	{
		if(node1 != NULL && node2 != NULL)
		{
			if(node1->val != node2->val)
				return false;
			else{
				if(solution(node1->left, node2->right) && solution(node1->right, node2->left))
					return true;
			}
		}else if(node1 != NULL && node2 == NULL || node1 == NULL && node2 != NULL)
		{
			return false;
		}else{
			return true;
		}
	}
	bool isSymmetric(TreeNode *root)
	{
		if(root == NULL || root->left == NULL && root->right == NULL)
			return true;
		return solution(root->left, root->right);
	}
};

int main(int argc, char const *argv[])
{
	TreeNode *root = new TreeNode(2);
	TreeNode *left = new TreeNode(3);
	TreeNode *right = new TreeNode(3);
	TreeNode *tmp1 = new TreeNode(4);
	TreeNode *tmp2 = new TreeNode(5);
	TreeNode *tmp3 = new TreeNode(5);
	root->left = left;
	left->left = tmp1;
	left->right = tmp2;
	root->right = right;
	right->left = tmp3;

	SymmetricTree s;
	cout << s.isSymmetric(root) << endl;

	delete root;
	delete left;
	delete right;
	delete tmp1;
	delete tmp2;
	delete tmp3;
	return 0;
}