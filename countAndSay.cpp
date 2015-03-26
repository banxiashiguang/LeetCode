#include <iostream>
#include <string>
using namespace std;

class countAndSay
{
public:
	countAndSay(){ }
	~countAndSay() { }
	string convert(string tmp);
	string solution(int n);
};

string countAndSay::convert(string tmp)
{
	string res = "";
	char ch = tmp[0];
	int count = 1;
	for(int i=1;i<tmp.size();i++)
	{
		if(tmp[i] == ch)
		{
			count++;
			continue;
		}else{
			res = res+(char)(count+'0')+ch;
			ch = tmp[i];
			count = 1;
		}
	}
	res = res+(char)(count+'0')+ch;
	return res;
}
string countAndSay::solution(int n)
{
	if(n<=0)
		return "";
	if(n==1)
		return "1";
	string res = "1";
	for(int i=1;i<n;i++)
		res = convert(res);
	return res;
}

int main(int argc, char const *argv[])
{
	int n = 1;
	countAndSay c;
	cout<<c.solution(3)<<endl;
	return 0;
}