#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

class Solution
{
public:
	string simplifyPath(string path)
	{
		string res = "";
		if(path.size() == 0)
			return res;
		//利用空格代替/
		for(int i = 0; i < path.size(); ++i)
		{
			if(path[i] == '/')
				path[i] = ' ';
		}
		
		istringstream sin(path);
		string str;
		stack<string> stack;
		while(sin >> str)
		{
			if(str == ".." && !stack.empty())
				stack.pop();
			else if(str == "." || str == ".." && stack.empty())
			{
			}else
				stack.push(str);
		}
		if(stack.empty())
			res += '/';
		while(!stack.empty())
		{
			res = '/' + stack.top() + res;
			stack.pop();
		}
		return res;
	}
};

int main(int argc,const char *argv[])
{
	Solution s;
	string str;
	while(cin >> str)
	{
		cout << s.simplifyPath(str) << endl;
	}
	return 0;
}
