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
		ListNode *slow = head;
		ListNode *fast = head->next;
		while(fast != NULL)
		{
			if(fast == slow)
				break;
			slow = slow->next;
			fast = fast->next;
			if(fast != NULL)
				fast = fast->next;
		}
		if(fast == NULL)
			return NULL;
		slow = head;
		while(slow != fast)
		{
			if(fast->next == slow)//两个节点的环
				return slow;
			slow = slow->next;
			fast = fast->next;
		}
		return fast;
	}
};

int main(int argc,const char *argv[])
{
	ListNode *head = new ListNode(1);
	ListNode *tmp = new ListNode(2);
	head->next = tmp;
	tmp->next = head;
	Solution s;
	ListNode *res = s.detectCycle(head);
	cout << res->val << endl;
	return 0;
}
