#include <iostream>
#include <string>
#include <stack>
using namespace std;

class validParentheses
{
public:
	validParentheses() { }
	~validParentheses() { }
	bool solution(string s);	
};

bool validParentheses::solution(string s)
{
	stack<char> charStack;
	int size = s.length();
	for(int i=0;i<size;i++)
	{
		if(s[i] == '(' || s[i] == '[' || s[i] == '{')
			charStack.push(s[i]);//入栈
		else
		{
			if(charStack.empty())
				return false;
			char tmp = charStack.top();
			if(s[i] == ')' && tmp != '(' || s[i] == ']' && tmp != '[' || s[i] == '}' && tmp != '{')
			{
				break;
			}
			charStack.pop();
		}
	}
	if(charStack.empty())
		return true;
	else
		return false;
}

int main(int argc, char const *argv[])
{
	string s = "[";
	validParentheses v;
	cout<<v.solution(s)<<endl;
	return 0;
}