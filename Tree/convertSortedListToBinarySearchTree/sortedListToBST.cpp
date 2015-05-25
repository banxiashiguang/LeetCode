#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(nullptr) { }
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr) { }
};

class Solution {
public:
	TreeNode* sortedListToBST(ListNode *head) {
		if(head == nullptr)
			return nullptr;
		ListNode *p = head;
		int count{0};
		while(p != nullptr) {
			++count;
			p = p->next;
		}
		ListNode *pre = nullptr;
		p = head;
		count >>= 1;
		while(count--) {
			pre = p;
			p = p->next;
		}
		TreeNode *root = new TreeNode(p->val);
		p = p->next;
		if(pre != nullptr) {
			pre->next = nullptr;
			root->left = sortedListToBST(head);
		}
		root->right = sortedListToBST(p);
		return root;
	}
};

void inOrder(TreeNode *root) {
	if(root == nullptr)
		return;
	inOrder(root->left);
	cout << root->val << "\t";
	inOrder(root->right);
}

int main(int argc,const char *argv[]) 
{
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(3);
	n1->next = n2;
	n2->next = n3;
	Solution s;
	TreeNode *root = s.sortedListToBST(n1);
	inOrder(root);
	delete n1;
	delete n2;
	delete n3;
	return 0;
}
