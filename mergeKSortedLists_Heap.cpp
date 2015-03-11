#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL) { }
};

bool cmp (ListNode *a,ListNode *b)
{
	return a->val > b->val;
}

class mergeKSortedLists_Heap
{
public:
	mergeKSortedLists_Heap(){}
	~mergeKSortedLists_Heap(){}
	ListNode *solution(vector<ListNode*> &lists);
};
void printVector(vector<ListNode*> &lists)
{
	for(int i=0;i<lists.size();i++)
		cout<<lists[i]->val<<"\t";
	cout<<endl;
}

ListNode * mergeKSortedLists_Heap::solution(vector<ListNode*> &lists)
{
	if(lists.size() == 0)
	{
		return NULL;
	}
	vector<ListNode*> tmp;
	ListNode *pNew = new ListNode(1);
	ListNode *pNext = pNew;
	for(int i=0;i<lists.size();i++)
	{
		if(lists[i] != NULL)
			tmp.push_back(lists[i]);
	}
	printVector(tmp);
	while(tmp.size() )
	{
		make_heap(tmp.begin(),tmp.end(),cmp);
		ListNode *p = tmp.front();
		pop_heap(tmp.begin(),tmp.end());
		tmp.pop_back();
		pNext->next = p;
		pNext = p;
		p = p->next;
		pNext->next = NULL;
		if(p != NULL)
			tmp.push_back(p);
	}
	pNext = pNew;
	pNew = pNew->next;
	pNext->next = NULL;
	delete pNext;
	return pNew;
}

int main(int argc, char const *argv[])
{
	ListNode *a1 = new ListNode(1);
	ListNode *a2 = new ListNode(10);
	ListNode *b1 = new ListNode(6);
	ListNode *b2 = new ListNode(12);
	ListNode *c1 = new ListNode(9);
	ListNode *c2 = new ListNode( 23);
	a1->next = a2;
	b1->next = b2;
	c1->next = c2;
	vector<ListNode*> lists;
	lists.push_back(a1);
	lists.push_back(b1);
	lists.push_back(c1);
	mergeKSortedLists_Heap m;
	vector<ListNode*> l;
	ListNode *res = m.solution(lists);
	while(res != NULL)
	{
		cout<<res->val<<"\t";
		res = res->next;
	}

	return 0;
}