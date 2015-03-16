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
	void solve(int n,int leftNum,int rightNum,string s);
	vector<string> solution(int n);
private:
	vector<string> res;
};

void generateParentheses::solve(int n,int leftNum,int rightNum,string s)
{
	if(leftNum < rightNum)
		return;
	if(leftNum + rightNum == 2*n)
	{
		if(leftNum == rightNum)
		{
			res.push_back(s);
		}
		return;
	}
	solve(n, leftNum+1, rightNum, s+"(");
	solve(n, leftNum, rightNum+1, s+")");
}

vector<string> generateParentheses::solution(int n)
{
	res.clear();
	solve(n, 0, 0, "");
	return res;
}

int main(int argc, char const *argv[])
{
	generateParentheses g;
	vector<string> res = g.solution(3);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<"\t";
	cout<<endl;
	return 0;
}