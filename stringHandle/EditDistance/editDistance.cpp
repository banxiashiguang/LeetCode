#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	int minDistance(string word1,string word2)
	{
		int m = word1.size();
		int n = word2.size();
		if(m == 0 || n == 0)
			return max(m,n);
		int dp[m+1][n+1];

		//从空字符串变成word2所需要的步骤
		for(int i = 0; i <= n; ++i)
			dp[0][i] = i;
		//从空字符串变成word1所需要的步骤
		for(int i = 0; i <= m; ++i)
			dp[i][0] = i;

		for(int i = 1; i <= m; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				if(word1[i-1] == word2[j-1])
					dp[i][j] = dp[i-1][j-1];
				else
					dp[i][j] = min(min(dp[i][j-1]+1,dp[i-1][j]+1),dp[i-1][j-1]+1);
			}
		}
		return dp[m][n];
	}
};

int main(int argc,const char *argv[])
{
	Solution s;
	string line,str1,str2;
	while(getline(cin,line))
	{
		cout << line << "测试用例" << endl;
		istringstream sin(line);
		sin >> str1 >> str2;
		cout << s.minDistance(str1,str2) << endl;
	}
}
