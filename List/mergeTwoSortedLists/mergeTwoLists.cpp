#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(nullptr) { }
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode *l1,ListNode *l2) {
		if(l1 == nullptr || l2 == nullptr)
			return l1 == nullptr? l2:l1;
		ListNode *head = nullptr;
		ListNode *p = nullptr;
		while(l1 != nullptr && l2 != nullptr) {
			ListNode *node = nullptr;
			if(l1->val < l2->val) {
				node = l1;
				l1 = l1->next;
			}else{
				node = l2;
				l2 = l2->next;
			}
			if(head == nullptr) {
				head = node;
				p = head;
			}else{
				p->next = node;
				p = p->next;
			}
		}
		if(l1 != nullptr)
			p->next = l1;
		if(l2 != nullptr)
			p->next = l2;
		return head;
	}
};

int main(int argc,const char *argv[])
{
	return 0;
}
