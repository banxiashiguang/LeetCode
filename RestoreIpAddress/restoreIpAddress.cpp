#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	//right：剩余未解析的字符串，left：已经解析的字符串，n：要解析的IP段(0-3)，res：保存格式正确的结果
	void backTracking(string right,string left,int n,vector<string> &res)
	{
		//首先判断剩余的字符串的个数是否满足后续解析的要求
		int len = right.size();
		if(len < 4-n || len > 3*(4-n))
			return;

		//设置递归函数的出口,最后一个IP段解析完成，即可退出
		if(n == 3)
		{
			//判断是否格式形如010,退出
			if(len > 1 && right[0] == '0')
				return;
			int value = stoi(right);
			if(value >= 0 && value <= 255)
			{
				left += right;
				cout << left << endl;
				res.push_back(left);
			}
			return;
		}

		//解析IP的前三个网段,个数可能是1、2、3个
		for(int i = 1; i< 4 && i < right.size(); ++i)
		{
			string str = right.substr(0,i);
			if(str.size() > 1 && str[0] == '0')
				return;
			int value = stoi(str);
			if(value >= 0 && value <= 255)
			{
				string next = left + str + ".";	
				backTracking(right.substr(i),next,n+1,res);
			}
		}
	}
	vector<string> restoreIpAddress(string s)
	{
		vector<string> res;
		if(s.size() < 4 || s.size() > 12)
			return res;
		backTracking(s,"",0,res);
		return res;
	}
};

int main(int argc,const char *argv[])
{
	Solution s;
	string str;
	while(cin >> str)
	{	
		cout << str << "解析：";
		vector<string> res = s.restoreIpAddress(str);
		for(auto i: res)
			cout<< i << endl;
	}
	return 0;	
}
