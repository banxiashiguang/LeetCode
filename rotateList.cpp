#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL) { }
};

class rotateList
{
public:
	rotateList() { }
	~rotateList() { }
	ListNode* solution(ListNode *head,int k);
};

ListNode* rotateList::solution(ListNode *head,int k)
{
	if(head == NULL)
		return head;
	int size = 0;
	ListNode *p = head;
	while(p->next != NULL)
	{
		++size;
		p = p->next;
	}
	++size;
	k %= size;
	if(size-k == 0)
		return head;
	int index =1;
	ListNode *pre = head;
	while(index++ < size-k)
		pre = pre->next;
	ListNode *after = pre->next;
	if(after == NULL)
		return head;
	p->next = head;
	pre->next = NULL;
	head = after;
	return head;
}

int main(int argc, char const *argv[])
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	rotateList r;
	ListNode *res = r.solution(NULL, 0);
	while(res != NULL)
	{
		cout << res->val <<"\t";
		res = res->next;
	}
	cout << endl;
	return 0;
}