#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const int LEFTUP = 0;
const int LEFT = 1;
const int UP = 2;

class Solution
{
public:
	string LCSquence(const string &str1,const string &str2)
	{
		int len1 = str1.size();
		int len2 = str2.size();
		string res;
		if(len1 == 0 || len2 == 0)
			return res;

		vector<vector<int> > value(len1+1,vector<int>(len2+1,0));
		vector<vector<int> > path(len1+1,vector<int>(len2+1,0));
		//预处理i=0,j=0的情况
		for(int i = 0; i < len2; ++i)
		{
			value[0][i] = 0;
			path[0][i] = 0;
		}
		for(int i = 0; i < len1; ++i)
		{
			value[i][0] = 0;
			path[i][0] = 0;
		}
		for(int i = 1; i <= len1; ++i)
		{
			for(int j = 1; j <= len2; ++j)
			{
				if(str1[i-1] == str2[j-1])
				{
					value[i][j] = value[i-1][j-1] + 1;
					path[i][j] = LEFTUP;
				}else{
					if(value[i-1][j] > value[i][j-1])
					{
						value[i][j] = value[i-1][j];
						path[i][j] = UP;
					}else{
						value[i][j] = value[i][j-1];
						path[i][j] = LEFT;
					}
				}
			}
		}
		int i = len1;
		int j = len2;
		while(i > 0 && j > 0)
		{
			if(path[i][j] == LEFTUP)
			{
				res += str1[i-1];
				--i;
				--j;
			}else if(path[i][j] == LEFT)
				--j;
			else
				--i;
		}
		reverse(res.begin(),res.end());
		cout << "长度=" << value[len1][len2] << "\t";
		return res;
	}
};

int main(int argc,const char *argv[])
{
	Solution s;
	string line;
	string str1,str2;
	while(getline(cin,line))
	{
		cout << line << "--------" << endl;
		istringstream sin(line);
		sin >> str1 >> str2;
		cout << s.LCSquence(str1,str2) << endl;
	}
	return 0;
}
