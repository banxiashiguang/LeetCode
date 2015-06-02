#include <iostream>
#include <memory>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(nullptr) { }
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA,ListNode *headB) {
		if(headA == nullptr || headB == nullptr)
			return nullptr;
		int lenA{0},lenB{0};
		ListNode *p = headA;
		while(p != nullptr) {
			++lenA;
			p = p->next;
		}
		p = headB;
		while(p != nullptr) {
			++lenB;
			p = p->next;
		}
		int diff = lenA-lenB;
		ListNode *pA{headA},*pB{headB};
		if(diff > 0) {
			while(diff-- > 0)
				pA = pA->next;
		}else if(diff < 0) {
			diff = -diff;
			while(diff-- > 0)
				pB = pB->next;
		}
		while(pA != nullptr && pB != nullptr) {
			if(pA == pB)
				return pA;
			pA = pA->next;
			pB = pB->next;
		}
		return nullptr;
	}
};

int main(int argc,const char *argv[])
{
	shared_ptr<ListNode> headA(new ListNode(1));
	shared_ptr<ListNode> headB(new ListNode(2));
	headA->next = headB.get();
	Solution s;
	ListNode *res = s.getIntersectionNode(headA.get(),headB.get());
	cout << res->val << endl;
	return 0;
}
