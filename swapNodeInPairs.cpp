#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL) { }
};

class swapNodeInPairs
{
public:
	swapNodeInPairs() { }
	~swapNodeInPairs() { }
	ListNode *solution(ListNode *head);
};

ListNode *swapNodeInPairs::solution(ListNode *head)
{
	if(head == NULL)
		return NULL;
	ListNode *p = head;
	ListNode *pre;
	while(p != NULL && p->next != NULL)
	{
		ListNode *tmp = p->next;
		p->next = tmp->next;
		tmp->next = p;
		if(p == head)
		{
			head = tmp;
			pre = p;
		}else{
			pre->next = tmp;
			pre = p;
		}
		p = p->next;
	}
	return head;
}

int main(int argc, char const *argv[])
{
	ListNode *a1 = new ListNode(1);
	ListNode *a2 = new ListNode(2);
	ListNode *a3 = new ListNode(3);
	ListNode *a4 = new ListNode(4);
	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	swapNodeInPairs s;
	ListNode *res = s.solution(a1);
	while(res != NULL)
	{
		cout<<res->val<<"\t";
		res = res->next;
	}
	cout<<endl;
	return 0;
}