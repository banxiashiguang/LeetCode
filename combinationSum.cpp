#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class combinationSum
{
public:
	combinationSum() { }
	~combinationSum() { };
	void dfs(int curSum,int curIndex,int target,vector<int> &curResault,vector<vector<int> > &resault,vector<int> can);
	vector<vector<int> > solution(vector<int> &candidates,int target);	
};

void combinationSum::dfs(int curSum,int curIndex,int target,vector<int> &curResault,vector<vector<int> > &resault,vector<int> can)
{
	if(curSum>target || curIndex>=can.size())
		return;
	if(curSum==target)
	{
		resault.push_back(curResault);
		return;
	}
	for(int i=curIndex;(i<can.size())&&(target-curSum>=can[i]);i++)
	{
		curSum += can[i];
		curResault.push_back(can[i]);
		dfs(curSum, i, target, curResault,resault,can);
		//go back
		curResault.pop_back();
		curSum -= can[i];
	}
}

vector<vector<int> > combinationSum::solution(vector<int> &candidates,int target)
{
	vector<vector<int> > re;
	vector<int> curRe;
	if(candidates.size() == 0)
		return re;
	sort(candidates.begin(),candidates.end());
	if(candidates[0] > target)
		return re;
	dfs(0, 0, target, curRe,re,candidates);
	return re;
}

int main(int argc, char const *argv[])
{
	int arrray[] = {1};
	vector<int> can(arrray,arrray+sizeof(arrray)/sizeof(arrray[0]));
	combinationSum c;
	vector<vector<int> > res = c.solution(can,1);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<"\t";
		cout<<endl;
	}
	return 0;
}