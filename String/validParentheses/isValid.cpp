#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> value;
		for(int i = 0; i < s.size(); ++i) {
			if(s[i] == '(' || s[i] == '{' || s[i] == '[')
				value.push(s[i]);
			else{
				if(value.size() <=0)
					return false;
				char c = value.top();
				value.pop();
				if(s[i] == ')' && c != '(' || s[i] == '}' && c != '{' || s[i] == ']' && c != '[')
					return false;
			}
		}
		if(value.size() > 0)
			return false;
		else
			return true;
	}
};

int main(int argc,const char *argv[])
{
	Solution s;
	cout << s.isValid("(()()(){}[]") << endl;
	return 0;
}
