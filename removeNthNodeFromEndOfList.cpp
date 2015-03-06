#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL) { }
};

class removeNthNodeFromEndOfList
{
public:
	removeNthNodeFromEndOfList() { }
	~removeNthNodeFromEndOfList() { }
	ListNode *solution(ListNode *head,int n);
};

ListNode * removeNthNodeFromEndOfList::solution(ListNode *head,int n)
{
	ListNode *p = head;
	int count = 1;
	while(p->next != NULL)
	{
		count++;
		p = p->next;
	}
	p = head;
	if(n == count)
	{
		head = p->next;
		p->next = NULL;
		return head;
	}
	for(int i=0;i<count-(n+1);i++)
	{
		p = p->next;
	}
	ListNode *tmp = p->next;
	p->next = tmp->next;
	tmp->next = NULL;
	return head;
}

int main(int argc, char const *argv[])
{
	int val;
	cout<<"Input the number";
	while(cin>>val)
	{
		ListNode
	}
	return 0;
}