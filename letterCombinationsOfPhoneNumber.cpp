#include <iostream>
#include <string>
#include <vector>
using namespace std;

class letterCombinationsOfPhoneNumber
{
public:
	letterCombinationsOfPhoneNumber() { }
	~letterCombinationsOfPhoneNumber() { }
	vector<string> solution(string digits);
};

vector<string> letterCombinationsOfPhoneNumber::solution(string digits)
{
	vector<string> res;
	int size = digits.length();
	if(size == 0)
		return res;
	string str[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	int len[] = {0,0,3,3,3,3,3,4,3,4};
	res.push_back("");
	for(int i=0;i<size;i++)
	{
		vector<string> tmpres;
		int num = digits[i]-'0';
		string tmp = str[num];
		for(int j=0;j<res.size();j++)
		{
			for(int x=0;x<tmp.size();x++)
			{
				tmpres.push_back(res[j]+tmp[x]);
			}
		}
		res = tmpres;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	letterCombinationsOfPhoneNumber l;
	string digits = "23";
	l.solution(digits);
	return 0;
}