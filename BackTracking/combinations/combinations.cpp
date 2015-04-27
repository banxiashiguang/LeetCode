#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution
{
public:
	void solve(vector<vector<int> > &res,vector<int> &curRes,int n,int k,int start)
	{
		if(k == 0)
			res.push_back(curRes);
		else
		{
			for(int i = start; i <= n; ++i)
			{
				curRes.push_back(i);
				solve(res,curRes,n,k-1,i+1);
				curRes.pop_back();
			}
		}
	}
	vector<vector<int> > combine(int n,int k)
	{
		vector<vector<int> > res;
		vector<int> curRes;
		solve(res,curRes,n,k,1);
		for(auto i: res)
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
	string line;
	int n,k;
	Solution s;
	while(getline(cin,line))
	{
		istringstream sin(line);
		sin >> n >> k;
		s.combine(n,k);
	}
}
