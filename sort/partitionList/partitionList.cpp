#include <iostream>
#include <memory>
#include <memory>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(nullptr) { }
};

class Solution
{
public:
	ListNode* partition(ListNode *head,int x)
	{
		if(head == nullptr)
			return head;
		ListNode *tail = nullptr;
		ListNode *prev = nullptr;
		ListNode *p = head;
		while(p != nullptr)
		{
			if(p->val >= x)
				break;
			prev = p;
			p = p->next;
		}
		tail = prev;
		while(p != nullptr)
		{
			if(p->val < x)
			{
				ListNode *tmp = p;
				p = p->next;
				prev->next = p;
				if(tail == nullptr)
				{
					tail = tmp;
					tail->next = head;
					head = tail;
				}else{
					tmp->next = tail->next;
					tail->next = tmp;
					tail = tmp;
				}
			}else{
				prev = p;
				p = p->next;
			}
		}
		return head;
	}
};


int main(int argc,const char *argv[])
{
	string line;
	int value;
	Solution s;
	unique_ptr<ListNode> head(new ListNode(1));
	unique_ptr<ListNode> node1(new ListNode(4));
	unique_ptr<ListNode> node2(new ListNode(3));
	unique_ptr<ListNode> node3(new ListNode(2));
	unique_ptr<ListNode> node4(new ListNode(5));
	unique_ptr<ListNode> node5(new ListNode(2));
	head->next = node1.get();
	node1->next = node2.get();
	node2->next = node3.get();
	node3->next = node4.get();
	node4->next = node5.get();
	ListNode *res = s.partition(head.get(),3);
	while(res != nullptr)
	{
		cout << res->val << "\t";
		res = res->next;
	}
	cout << endl;
	return 0;
}
