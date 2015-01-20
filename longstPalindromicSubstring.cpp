#include <iostream>
#include <string>
using namespace std;

class longstPalindromicSubstring
{
public:
	longstPalindromicSubstring() { }
	~longstPalindromicSubstring() { }
	string sulotion(string s);
};

//暴力解法，时间复杂度为O(N^3)。
/*string longstPalindromicSubstring::sulotion(string s)
{
	int len = s.size();
	int start,end;
	int maxlen = 0;
	string sub;
	for(int i = 0;i <len-1;i++)
	{
		for(int j = i+1;j < len;j++)
		{
			start = i;
			end = j;
			while((start <= end) && (s[start] == s[end]))
			{
				start++;
				end--;
			}
			if(start > end)
			{
				if((i+j+1) > maxlen)
				{
					maxlen = i+j+1;
					sub = s.substr(i,maxlen);
				}
			}
		}
	}
	return sub;
}*/

//采用动态规划，时间复杂度为O(N^2)
string longstPalindromicSubstring::sulotion(string s)
{
	int len = s.length();
	int longstBegin = 0;
	int maxlen = 1;
	int i,j;
	if(len <= 0)
		return 0;
	int status[1000][1000] = {0};

	for(i=0;i<len;i++)
	{
		status[i][i] = 1;
	}

	for(i=0;i<len-1;i++)
	{
		if(s[i] == s[i+1])
		{
			status[i][i+1] = 1;
			longstBegin = i;
			maxlen = 2;
		}
	}

	for(i=3;i<=len;i++)
	{
		for(j=0;j<len-i+1;j++)
		{
			int tmp = j+i-1;//子字符串的最后一个字符位置
			if(s[j] == s[tmp] && status[j+1][tmp-1])
			{
				longstBegin = j;
				maxlen = i;
				status[j][tmp] = 1;
			}
		}
	}
	return s.substr(longstBegin,maxlen);
}

int main(int argc, char const *argv[])
{
	string s = "abac";
	longstPalindromicSubstring sub;
	cout<<sub.sulotion(s)<<endl;
	return 0;
}