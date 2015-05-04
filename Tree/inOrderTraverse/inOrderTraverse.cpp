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

//中序递归遍历，左中右
void recursiveInOrderTraverse(TreeNode *root)
{
	if(root == nullptr)
		return;
	recursiveInOrderTraverse(root->left);
	cout << root->val << "\t";
	recursiveInOrderTraverse(root->right);
}

//中序非递归遍历
void noRecInOrderTraverse(TreeNode *root)
{
	if(root == nullptr)
		return;
	stack<TreeNode *> value;
	value.push(root);
	TreeNode *p = root->left;
	//增加p != nullptr是为了防止，遍历到跟节点后，value为空，但p指向根节点的右子树。
	while(!value.empty() || p != nullptr)
	{
		//从根节点到最左下方的节点入栈
		while(p != nullptr)
		{
			value.push(p);
			p = p->left;
		}
		TreeNode *node = value.top();
		value.pop();
		cout << node->val << "\t";
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
	root->left = left.get();
    root->right = right.get();
    left->left = tmp1.get();
    right->left = tmp2.get();
    right->right = tmp3.get();
    cout << "递归" << endl;
    recursiveInOrderTraverse(root.get());
    cout << endl;
	cout << "非递归" << endl;
    noRecInOrderTraverse(root.get());
    cout << endl;
	return 0;
}
