#include <iostream>
#include <string>

using namespace std;

class romanToInteger
{
public:
	romanToInteger() { }
	~romanToInteger() { }
	int solution(string s);
	
};

int romanToInteger::solution(string s)
{
	int res = 0;
	int last = 0;
	int data[] = {1,5,10,50,100,500,1000};
	char roman[] = {'I','V','X','L','C','D','M'};
	for(int i=0;i<s.length();i++)
	{
		for(int j=0;j<7;j++)
		{
			if(s[i] == roman[j])
			{
				res += data[j];
				if(data[j] > last)
					res -= 2*last;
					last = data[j];
			}
		}
	}
	return res;
}
int main(int argc, char const *argv[])
{
	romanToInteger r;
	string s = "IV";
	cout<<r.solution(s)<<endl;
	return 0;
}