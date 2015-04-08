#include <iostream>
#include <string>
using namespace std;

class binaryAdd
{
public:
	binaryAdd() { }
	~binaryAdd() { }
	string solution(string a,string b);
};

string binaryAdd::solution(string a,string b)
{
	string res = "";
	int flags = 0;
	int aSize = a.size()-1;
	int bSize = b.size()-1;
	int index = 0;
	while(index < a.size() && index < b.size())
	{
		int mod = (a[aSize]-'0'+b[bSize]-'0'+flags)%2;
		res = (char)(mod+'0')+res;
		flags = (a[aSize]-'0'+b[bSize]-'0'+flags)/2;
		aSize--;
		bSize--;
		index++;
	}
	if(index < a.size())
	{
		while(index < a.size())
		{
			int mod = (a[aSize]-'0'+flags)%2;
			flags = (a[aSize--]-'0'+flags)/2;
			res = (char)(mod+'0')+res;
			index++;
		}
	}
	if(index < b.size())
	{
		while(index < b.size())
		{
			int mod = (b[bSize]-'0'+flags)%2;
			flags = (b[bSize--]-'0'+flags)/2;
			res = (char)(mod+'0')+res;
			index++;
		}
	}
	if(flags == 1)
		res = (char)(flags+'0')+res;
	return res;
}

int main(int argc, char const *argv[])
{
	binaryAdd b;
	cout << b.solution("101111", "10") << endl;
	return 0;
}