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
		if(head == NULL)
			return NULL;
		ListNode* prev = head;
		ListNode* p = head->next;
		int last = head->val;
		while(p != NULL)
		{
			if(p->val == last)
			{
				ListNode *tmp = p;
				prev->next = p->next;
				p = p->next;
				tmp->next = NULL;
				delete tmp;
			}else{
				last = p->val;
				prev = p;
				p = p->next;
			}
		}
		return head;
	}
};

int main(int argc,const char *argv[])
{

	return 0;
}
