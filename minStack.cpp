#include <iostream>
#include <limits>
using namespace std;


class MinStack
{
	struct Node
	{
		int val;
		Node *next;
		Node(int x):val(x),next(NULL) { }
	};
private:
	Node *head;
public:
	MinStack(){
		head = new Node((numeric_limits<int>::max()));
	}
	~MinStack(){
		delete head;
	}
	//利用头插法，在插入的过程中，记录最小值。
	void push(int x)
	{
		Node *p = new Node(x);
		if(head->val > p->val)
			head->val = p->val;
		p->next = head->next;
		head->next = p;
	}
	void pop()
	{
		if(head->next == NULL)
			return;
		Node *p = head->next;
		head->next = p->next;
		p->next = NULL;
		if(head->val == p->val)
		{
			head->val = numeric_limits<int>::max();
			Node *tmp = head->next;
			while(tmp != NULL)
			{
				if(tmp->val < head->val)
					head->val = tmp->val;
				tmp = tmp->next;
			}
		}
		delete p;
	}
	int top()
	{
		return head->next->val;
	}
	int getMin()
	{
		return head->val;
	}
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}