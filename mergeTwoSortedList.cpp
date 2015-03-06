#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL) { }
};

class mergeTwoSortedList
{
public:
	mergeTwoSortedList() { }
	~mergeTwoSortedList() { }
	ListNode* solution(ListNode* l1,ListNode* l2);	
};

ListNode* mergeTwoSortedList::solution(ListNode* l1,ListNode* l2)
{
	ListNode *pOne,*pTwo,*p;
	ListNode *pNew = new ListNode(1);
	p = pNew;
	pOne = l1;
	pTwo = l2;
	while(pOne != NULL && pTwo != NULL)
	{
		if(pOne->val < pTwo->val)
		{
			p->next = pOne;
			pOne = pOne->next;	
		}else{
			p->next = pTwo;
			pTwo = pTwo->next;
		}
		p = p->next;
		p->next = NULL;
	}
	if(pOne != NULL)
	{
		while(pOne != NULL)
		{
			p->next = pOne;
			pOne = pOne->next;
			p = p->next;
			p->next = NULL;
		}
	}
	if(pTwo != NULL)
	{
		while(pTwo != NULL)
		{
			p->next = pTwo;
			pTwo = pTwo->next;
			p = p->next;
			p->next = NULL;
		}
	}
	p = pNew;
	pNew = p->next;
	delete p;	
	return pNew;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}