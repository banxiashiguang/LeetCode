/**
思路：假设当前字串已经有r个"("，t个“)”，则
1若r=n,且t<n时，则只能向该字串中添加")";
2.若r=t,且t<n时，，则只能向该字串中添加"（";
3.若r>t,且t<n时，，则有两种方案 向该字串中添加"（"; 复制该字串，向复制的字符串中添加“)”
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class generateParentheses
{
public:
	generateParentheses() { }
	~generateParentheses() { }
	vector<string> solution(int n);
private:
	vector<string> res;
};

vector<string> generateParentheses::solution(int n)
{
	
}