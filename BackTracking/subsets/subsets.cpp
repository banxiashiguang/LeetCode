#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	void backTracking(vector<vector<int> > &res,vector<int> &curRes,vector<int> &S,int k,int start)
	{
		if(k == 0)
			res.push_back(curRes);
		for(int i = start; i < S.size(); ++i)
		{
			curRes.push_back(S[i]);
			backTracking(res,curRes,S,k-1,i+1);
			curRes.pop_back();
		}
	}
	vector<vector<int> > subsets(vector<int> &S)
	{
		vector<vector<int> > res;
		sort(S.begin(),S.end());
		for(int i = 0; i <= S.size(); ++i)
		{
			vector<int> tmp;
			backTracking(res,tmp,S,i,0);
		}
		for(auto i:res)
		{
			for(auto j:i)
				cout << j << "\t";
			cout << endl;
		}
		return res;
	}
};

int main(int argc,const char *argv[])
{
	Solution s;
	string line;
	int value;
	while(getline(cin,line))
	{
		vector<int> S;
		istringstream sin(line);
		while(sin >> value)
			S.push_back(value);
		s.subsets(S);
	}
	return 0;
}
