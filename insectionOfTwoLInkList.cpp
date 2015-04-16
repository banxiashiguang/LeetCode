#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL) { }
};

class insectionOfTwoLInkList
{
public:
	insectionOfTwoLInkList() { }
	~insectionOfTwoLInkList() { }
	int getLen(ListNode *head);
	void eliminateDiff(ListNode *headA,int lenA,ListNode *headB,int lenB);
	ListNode* solution(ListNode *headA,ListNode *headB);
};

int insectionOfTwoLInkList::getLen(ListNode *head)
{
	ListNode *p = head;
	int res = 0;
	while(p != NULL)
	{
		++res;
		p = p->next;
	}
	return res;
}

ListNode* insectionOfTwoLInkList::solution(ListNode *headA,ListNode *headB)
{
	if(headA == NULL || headB == NULL)
		return NULL;
	ListNode *pA = headA;
	ListNode *pB = headB;
	int lenA = getLen(headA);
	int lenB = getLen(headB);

	int diff = lenA - lenB;
	if(diff > 0)
	{
		while(diff > 0)
		{
			pA = pA->next;
			--diff;
		}
	}else{
		while(diff < 0)
		{
			pB = pB->next;
			++diff;
		}
	}

	while(pA != NULL && pB != NULL)
	{
		if(pA == pB)
			return pA;
		else
		{
			pA = pA->next;
			pB = pB->next;
		}
	}
	return NULL;
}

int main(int argc, char const *argv[])
{
	ListNode *headA = new ListNode(2);
	ListNode *headB = new ListNode(3);
	headA->next = headB;
	insectionOfTwoLInkList i;
	ListNode *res = i.solution(headA, headB);
	cout << res->val << endl;
	delete headA;
	delete headB;
	return 0;
}