#include <iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL) { }
};
int binary_search(int A[],int n,int target);//二分查找
int depth_first_search(TreeNode *root,int target);