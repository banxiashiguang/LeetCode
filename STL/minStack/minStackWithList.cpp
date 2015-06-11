#include <iostream>
#include <limits>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(nullptr) { }
};

class MinStack {
private:
	ListNode *head;
	int min;
public:
	MinStack():head(nullptr),min(numeric_limits<int>::max()) { }
	void push(int x) {
		ListNode *node = new ListNode(x);
		if(x < min)
			min = x;
		if(head == nullptr)
			head = node;
		else{
			node->next = head;
			head = node;
		}
	}
	void pop() {
		if(head == nullptr)
			return;
		ListNode *node = head;
		head = head->next;
		if(node->val == min) {
			ListNode *p = head;
			min = numeric_limits<int>::max();
			while(p != nullptr) {
				if(p->val < min)
					min = p->val;
				p = p->next;
			}
		}
		delete node;
	}
	int top() {
		if(head != nullptr)
			return head->val;
	}
	int getMin() {
		return min;
	}
};

int main(int argc,const char *argv[])
{
	MinStack stack;
	vector<int> nums{-2,0,-1};
	for(auto i:nums) {
		stack.push(i);
	}
	cout << stack.getMin() << endl;
	cout << stack.top() << endl;
	stack.pop();
	cout << stack.getMin() << endl;
	return 0;
}
