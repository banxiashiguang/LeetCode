#include <iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *parent;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),parent(nullptr),left(nullptr),right(nullptr) { }
};

class Solution
{
public:
	TreeNode* createNode(int x)
	{
		TreeNode *pNode = new TreeNode(x);
		return pNode;
	}

};
