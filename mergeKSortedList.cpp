//利用分治的思想把合并k个链表分成两个合并k/2个链表的任务，一直划分，
//知道任务中只剩一个链表或者两个链表。可以很简单的用递归来实现。因此算法复杂度为T(k) = 2T(k/2) + O(nk),很简单可以推导得到算法复杂度为O（nklogk）
#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL) { }
};

class mergeKSortedList
{
public:
	mergeKSortedList() { }
	~mergeKSortedList() { }
	ListNode *mergeTwoList(ListNode *l1,ListNode* l2);
	ListNode *solution(vector<ListNode*> &lists);
};

ListNode* mergeKSortedList::mergeTwoList(ListNode *l1,ListNode *l2)
{
	ListNode *pOne,*pTwo,*p;
	ListNode *pNew = new ListNode(1);
	p = pNew;
	pOne = l1;
	pTwo = l2;
	while(pOne != NULL && pTwo != NULL)
	{
		if(pOne->val < pTwo->val)
		{
			p->next = pOne;
			pOne = pOne->next;	
		}else{
			p->next = pTwo;
			pTwo = pTwo->next;
		}
		p = p->next;
		p->next = NULL;
	}
	if(pOne != NULL)
	{
		while(pOne != NULL)
		{
			p->next = pOne;
			pOne = pOne->next;
			p = p->next;
			p->next = NULL;
		}
	}
	if(pTwo != NULL)
	{
		while(pTwo != NULL)
		{
			p->next = pTwo;
			pTwo = pTwo->next;
			p = p->next;
			p->next = NULL;
		}
	}
	p = pNew;
	pNew = p->next;
	delete p;	
	return pNew;
}

ListNode* mergeKSortedList::solution(vector<ListNode*> &lists)
{
	int size = lists.size();
	if(size == 0)
		return NULL;
	while(size > 1)
	{
		int k = (size+1)/2;
		for(int i=0;i<size/2;i++)
		{
			lists[i] = mergeTwoList(lists[i], lists[i+k]);
		}
		size = k;
	}
	return lists[0];
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}