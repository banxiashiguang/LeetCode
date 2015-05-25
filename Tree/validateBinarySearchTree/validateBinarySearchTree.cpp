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
	Solution():value(0) { }
	bool isValidBST(TreeNode *root) {
		if(root == nullptr)
			return true;
		stack<TreeNode *> node;
		node.push(root);
		bool flags = false;
		TreeNode *p = root->left;
		while(!node.empty() || p != nullptr)
		{
			while(p != nullptr)
			{
				node.push(p);
				p = p->left;
			}
			TreeNode *tmp = node.top();
			node.pop();
			if(!flags) {
				flags = true;
				value = tmp->val;
			}else {
				if(tmp->val <= value)
					return false;
				value = tmp->val;
			}
			p = tmp->right;
		}
		return true;
	}
private:
	int value;
};

int main(int argc,const char *argv[])
{

	Solution s;
    TreeNode *root = new TreeNode(10);
    TreeNode *left = new TreeNode(5);
    TreeNode *right = new TreeNode(15);
    TreeNode *pT1 = new TreeNode(6);
    TreeNode *pT2 = new TreeNode(20);
	root->left = left;
	root->right = right;
	right->left = pT1;
	right->right = pT2;
	cout << s.isValidBST(root) << endl;
    delete root;
    delete left;
    delete right;
    delete pT1;
    delete pT2;
	return 0;
}
