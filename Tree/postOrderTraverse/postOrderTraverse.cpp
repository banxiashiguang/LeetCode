#include <iostream>
#include <stack>
#include <memory>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr) { }
};


//后序递归遍历，左右根
void recursivePostOrderTraverse(TreeNode *root)
{
	if(root == nullptr)
		return;
	recursivePostOrderTraverse(root->left);
	recursivePostOrderTraverse(root->right);
	cout << root->val << "\t";
}

//后序非递归遍历
void noRecPostOrderTraverse(TreeNode *root)
{
	if(root == nullptr)
		return;
	stack<TreeNode *> value;
	value.push(root);
	TreeNode *p = root->left;
	TreeNode *visit = nullptr;//指向前一个被访问的节点
	while(!value.empty())
	{
		while(p != nullptr)
		{
			value.push(p);
			p = p->left;
		}
		TreeNode *node = value.top();
		//当前节点的右孩子为空或者已经被访问过
		if(node->right == nullptr || node->right == visit)
		{
			value.pop();
			cout << node->val << "\t";
			visit = node;
			p = nullptr;
		}else
			p = node->right;
	}
}


int main(int argc,const char *argv[])
{
	shared_ptr<TreeNode> root(new TreeNode(1));
    shared_ptr<TreeNode> left(new TreeNode(2));
    shared_ptr<TreeNode> right(new TreeNode(3));
	shared_ptr<TreeNode> tmp1(new TreeNode(4));
	shared_ptr<TreeNode> tmp2(new TreeNode(5));
	shared_ptr<TreeNode> tmp3(new TreeNode(6));
	shared_ptr<TreeNode> tmp4(new TreeNode(7));
    root->left = left.get();
	root->right = right.get();
	left->left = tmp1.get();
	tmp1->right = tmp4.get();
    right->left = tmp2.get();
	right->right = tmp3.get();
	cout << "递归" << endl;
	recursivePostOrderTraverse(root.get());
    cout << endl;
    cout << "非递归" << endl;
    noRecPostOrderTraverse(root.get());
    cout << endl;
	return 0;
}
