#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(nullptr) { }
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode *head,int n) {
		if(head == nullptr || n <= 0)
			return head;
		int count{0};
		ListNode *p = head;
		while(p != nullptr) {
			p = p->next;
			++count;
		}
		if(n > count)
			return head;
		ListNode *pre = nullptr;
		p = head;
		int diff = count-n;
		while(diff-- > 0) {
			pre = p;
			p = p->next;
		}
		cout << p->val << endl;
		if(pre)
			pre->next = p->next;
		else
			head = head->next;
		p->next = nullptr;
		delete p;
		p = nullptr;
		return head;
	}
};

int main(int argc,const char *argv[])
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	Solution s;
	ListNode *res = s.removeNthFromEnd(head,2);
	while(res != nullptr) {
		ListNode *node = res;
		res = res->next;
		delete node;
	}
	return 0;
}
