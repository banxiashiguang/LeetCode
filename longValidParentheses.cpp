/*1、维护一个栈，栈底元素为上次匹配失败的位置。
 *2、首先初始放一个-1入栈代表上次匹配失败的地方为-1。
 *3、若下一个为'('，则将当前位置push到栈中。
 *4、若下一个为')'，首先判断栈的大小，若大于1：匹配'('；否则，更新栈底的值。
 */
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class longValidParentheses
{
public:
	longValidParentheses() { }
	~longValidParentheses() { }
	int solution(string s);
};

int longValidParentheses::solution(string s)
{
	int maxLen = 0;
	stack<int> sk;
	sk.push(-1);
	for(int i=0;i<s.size();i++)
	{
		char c = s[i];
		if(c == '(')
			sk.push(i);
		else{
			if(sk.size()>1)
			{
				sk.pop();
				int tmp = sk.top();
				maxLen = max(maxLen,i-tmp);
			}else{
				sk.pop();
				sk.push(i);
			}
		}
	}
	return maxLen;
}

int main(int argc, char const *argv[])
{
	string s = "))()()";
	longValidParentheses l;
	cout<<l.solution(s)<<endl;
	return 0;
}