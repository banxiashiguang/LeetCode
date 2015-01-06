#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL) {}
};

class addTwoNumber
{
public:
	addTwoNumber() { }
	~addTwoNumber() { }
	ListNode* solution(ListNode *listOne,ListNode *listTwo);
};

ListNode* addTwoNumber::solution(ListNode *listOne,ListNode *listTwo)
{
	ListNode *header,*p;
	int sum = listOne->val+listTwo->val;
	int dev = sum/10;
	int mod = sum%10;
	p = new ListNode(mod);
	header = p;
	listOne = listOne->next;
	listTwo = listTwo->next;
	while(listOne != NULL && listTwo != NULL)
	{
		sum = listOne->val+listTwo->val+dev;
		dev = sum/10;
		mod = sum%10;
		ListNode* tmp = new ListNode(mod);
		p->next = tmp;
		p = p->next;
		listOne = listOne->next;
		listTwo = listTwo->next;
	}
	while(listOne != NULL)
	{
		sum = listOne->val+dev;
		dev = sum/10;
		mod = sum%10;
		ListNode *tmp = new ListNode(mod);
		p->next = tmp;
		p = p->next;
		listOne = listOne->next;
	}
	while(listTwo != NULL)
	{
		sum = listTwo->val+dev;
		dev = sum/10;
		mod = sum%10;
		ListNode *tmp = new ListNode(mod);
		p->next = tmp;
		p = p->next;
		listTwo = listTwo->next;
	}
	if(dev > 0)
	{
		ListNode *tmp = new ListNode(dev);
		p->next = tmp;
		p = p->next;
	}
	return header;
}

int main(int argc, char const *argv[])
{
	ListNode *listOne,*listTwo,*pOne,*pTwo,*p;
	int number;
	cout<<"输入第一个数据：";
	cin>>number;
	p = new ListNode(number);
	listOne = pOne = p;
	cout<<"输入其余数据：";
	while(cin>>number)
	{
		if(number == -1)
			break;
		else{
			p = new ListNode(number);
			pOne->next = p;
			pOne = pOne->next;
		}
	}

	cout<<"输入第一个数据：";
	cin>>number;
	p = new ListNode(number);
	listTwo = pTwo = p;
	cout<<"输入其余数据：";
	while(cin>>number)
	{
		if(number == -1)
			break;
		else{
			p = new ListNode(number);
			pTwo->next = p;
			pTwo = pTwo->next;
		}
	}
	addTwoNumber add;
	ListNode *resault = add.solution(listOne, listTwo);
	while(resault != NULL)
	{
		cout<<resault->val<<endl;
		resault = resault->next;
	}
	return 0;
}