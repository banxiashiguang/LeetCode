#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class combinationSumII
{
public:
	combinationSumII() { }
	~combinationSumII() { }
	void dfs(int curSum,int curIndex,int target,vector<int> &curResault,set<vector<int> > &resault,vector<int> can);
	vector<vector<int> > solution(vector<int> &candidates,int target);
};

void combinationSumII::dfs(int curSum,int curIndex,int target,vector<int> &curResault,set<vector<int> > &resault,vector<int> can)
{
	if(curSum==target)
	{
		resault.insert(curResault);
		return;
	}
	if(curSum>target || curIndex>=can.size())
		return;
	for(int i=curIndex;(i<can.size())&&(target-curSum>=can[i]);i++)
	{
		curSum += can[i];
		curResault.push_back(can[i]);
		dfs(curSum, i+1, target, curResault,resault,can);
		curResault.pop_back();
		curSum -= can[i];
	}
}

vector<vector<int> > combinationSumII::solution(vector<int> &num,int target)
{
	vector<int> curRe;
	set<vector<int> >re;
	vector<vector<int> > resault;
	if(num.size() == 0)
		return resault;
	sort(num.begin(),num.end());
	if(num[0]>target)
		return resault;
	dfs(0, 0, target, curRe,re,num);
	resault.assign(re.begin(),re.end());
	return resault;+
}

int main(int argc, char const *argv[])
{
	int arrray[] = {1,1};
	vector<int> can(arrray,arrray+sizeof(arrray)/sizeof(arrray[0]));
	combinationSumII c;
	vector<vector<int> > res = c.solution(can,1);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<"\t";
		cout<<endl;
	}
	return 0;
}