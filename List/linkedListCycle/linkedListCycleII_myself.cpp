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
	ListNode* detectCycle(ListNode *head)
	{
		if(head == NULL)
			return NULL;	
		ListNode *slow = head;
		ListNode *fast = head->next;
		bool hasCycle = false;
		while(fast != NULL)
		{
			if(slow == fast)
			{
				hasCycle = true;
				break;
			}
			slow = slow->next;
			fast = fast->next;
			if(fast != NULL)
				fast = fast->next;
		}
		cout << hasCycle << endl;
		if(hasCycle)
		{
			ListNode *p = head;
			while(p != slow)
			{
				if(fast->next == p)
					return p;
				fast = fast->next;
				while(fast != slow)
				{
					if(fast->next == p)
						return p;
					fast = fast->next;
				}
				p = p->next;
			}
			return p;
		}else{
			return NULL;
		}
	}
};

int main(int argc,const char *argv[])
{
	ListNode *head = new ListNode(3);
	ListNode *tmp1 = new ListNode(2);
	ListNode *tmp2 = new ListNode(0);
	ListNode *tmp3 = new ListNode(-4);
	//head->next = tmp1;
	tmp1->next = tmp1 ;
	tmp2->next = tmp3;
	tmp3->next = tmp1;

	Solution s;
	ListNode *res = s.detectCycle(head);
	//cout << res->val << endl;
	delete head;
	delete tmp1;
	delete tmp2;
	delete tmp3;
	return 0;
}
