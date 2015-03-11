#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL) { }
};

class reverseNodesKGroup
{
public:
	reverseNodesKGroup() { }
	~reverseNodesKGroup() { }
	int nodeNum(ListNode *head);
	void reverseNodes(int k);
	ListNode *solution(ListNode *head,int k);
private:
	ListNode *pre;
	ListNode *subHead;
};

int reverseNodesKGroup::nodeNum(ListNode *head)
{
	ListNode *p = head;
	int res = 0;
	while(p != NULL)
	{
		res++;
		p = p->next;
	}
	return res;
}

void reverseNodesKGroup::reverseNodes(int k)
{
	subHead = subHead->next;
	ListNode *tail = pre->next;
	for(int i=1;i<k;i++)
	{
		ListNode *tmp = subHead->next;
		subHead->next = pre->next;
		pre->next = subHead;
		subHead = tmp;
	}
	tail->next = subHead;
	pre = tail;
}

ListNode *reverseNodesKGroup::solution(ListNode *head,int k)
{
	int size = nodeNum(head);
	if(size < k)
		return head;
	ListNode *p = new ListNode(-11);
	pre = p;
	p->next = head;
	subHead = head;
	for(int i=0;i<size/k;i++)
		reverseNodes(k);
	head = p->next;
	p->next = NULL;
	delete p;
	return head;
}

int main(int argc, char const *argv[])
{
	ListNode *a1 = new ListNode(1);
	ListNode *a2 = new ListNode(2);
	ListNode *a3 = new ListNode(3);
	ListNode *a4 = new ListNode(4);
	ListNode *a5 = new ListNode(5);
	ListNode *a6 = new ListNode(6);
	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = a5;
	a5->next = a6;
	reverseNodesKGroup r;
	ListNode *res = r.solution(a1, 3);
	while(res != NULL)
	{
		cout<<res->val<<"\t";
		res = res->next;
	}
	cout<<endl;
	return 0;
}