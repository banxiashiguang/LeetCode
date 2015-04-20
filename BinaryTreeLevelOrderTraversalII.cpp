#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL) { }
};

class BinaryTreeLevelOrderTraversalII
{
public:
	BinaryTreeLevelOrderTraversalII() { }
	~BinaryTreeLevelOrderTraversalII() { }

	/**
	 * 广度优先搜索(BFS):在将每一层元素所有元素压如到queue中，并在之后加入一个NULL。
	 * @param root [description]
	 */
	void breathFirstSearch(TreeNode *root,vector<vector<int> > &res)
	{
		vector<int> tmp;
		queue<TreeNode*> nodeQueue;
		nodeQueue.push(root);
		nodeQueue.push(NULL);
		while(nodeQueue.size() > 1)
		{
			TreeNode *node = nodeQueue.front();
			nodeQueue.pop();
			if(node == NULL)
			{
				res.push_back(tmp);
				tmp.clear();
				nodeQueue.push(NULL);
				continue;
			}
			tmp.push_back(node->val);
			if(node->left != NULL)
				nodeQueue.push(node->left);
			if(node->right != NULL)
				nodeQueue.push(node->right);
		}
		res.push_back(tmp);
	}

	vector<vector<int> > levelOrderBottom(TreeNode *root)
	{
		vector<vector<int> > res;
		if(root == NULL)
			return res;
		breathFirstSearch(root, res);
		reverse(res.begin(),res.end());
		return res;
	}
};

int main(int argc, char const *argv[])
{
	TreeNode *root = new TreeNode(1);
	TreeNode *left = new TreeNode(2);
	TreeNode *right = new TreeNode(3);
	TreeNode *tmp1 = new TreeNode(4);
	TreeNode *tmp2 = new TreeNode(5);
	root->left = left;
	root->right = right;
	left->left = tmp1;
	tmp1->left = tmp2;
	BinaryTreeLevelOrderTraversalII b;
	vector<vector<int> > res = b.levelOrderBottom(root);
	for(int i = 0;i < res.size(); ++i)
	{
		for(auto j: res[i])
			cout << j << "\t";
		cout << endl;
	}
	delete root;
	delete left;
	delete right;
	delete tmp1;
	delete tmp2;
	return 0;
}