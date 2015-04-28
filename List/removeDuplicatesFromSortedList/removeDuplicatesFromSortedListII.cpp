#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL) { }
};

class Solution
{
public:
	ListNode* deleteDuplicates(ListNode *head)
	{
		if(head == NULL || head->next == NULL)
			return head;
		ListNode *prev = head;
		ListNode *p = head->next;
		ListNode *newHead = new ListNode(-1);
		ListNode *tail = newHead;
		int last = head->val;
		int count = 0;
		while(p != NULL)
		{
			if(p->val == last)
			{
				++count;
				p = p->next;
			}else{
				if(count > 0)
				{
					while(prev != p)
					{
						ListNode *tmp = prev;
						prev = prev->next;
						tmp->next = NULL;
						delete tmp;
					}
					count = 0;
					tail->next = prev;
					last = p->val;
					p = p->next;
				}else{
					last = p->val;
					tail->next = prev;
					tail = tail->next;
					prev = p;
					p = p->next;
				}
			}
		}
		if(count > 0)
			tail->next = NULL;
		head = newHead->next;
		newHead->next = NULL;
		delete newHead;
		return head;
	}
};

int main(int argc,const char *argv[])
{
	Solution s;
	ListNode *head = new ListNode(1);
	ListNode *tmp1 = new ListNode(2);
	head->next = tmp1;
	ListNode *tmp2 = new ListNode(2);
	tmp1->next = tmp2;
	ListNode *tmp3 = new ListNode(3);
	//tmp2->next = tmp3;
	ListNode *tmp4 = new ListNode(4);
	tmp3->next = tmp4;
	ListNode *tmp5 = new ListNode(4);
	tmp4->next = tmp5;
	ListNode *tmp6 = new ListNode(6);
	tmp5->next = tmp6;
	ListNode *p = head;
	while(p != NULL)
	{
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;
	
	ListNode *res = s.deleteDuplicates(head);
	p = res;
	while(p != NULL)
	{
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;
	delete head;
	delete tmp1;
	delete tmp2;
	delete tmp3;
	delete tmp4;
	delete tmp5;
	delete tmp6;
	return 0;
}
