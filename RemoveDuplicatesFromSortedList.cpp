#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL) { }
};

class RemoveDuplicatesFromSortedList
{
public:
	RemoveDuplicatesFromSortedList() { }
	~RemoveDuplicatesFromSortedList() { }
	ListNode* deleteDuplicates(ListNode *head)
	{
		if(head == NULL)
			return head;
		ListNode *p = head->next;
		ListNode *pre = head;
		int last = head->val;
		while(p != NULL)
		{
			if(p->val == last)
			{
				ListNode *tmp = p;
				p = p->next;
				pre->next = p;
				tmp->next = NULL;
				delete tmp;
			}else{
				last = p->val;
				pre = p;
				p = p->next;
			}
		}
		return head;
	}
};

int main(int argc, char const *argv[])
{
	ListNode *head = new ListNode(1);
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(3);
	ListNode *p4 = new ListNode(3);
	head->next = p1;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	RemoveDuplicatesFromSortedList r;
	ListNode *res = r.deleteDuplicates(head);
	ListNode *p = head;
	while(p != NULL)
	{
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;
	return 0;
}