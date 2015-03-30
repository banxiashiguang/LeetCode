
#include <iostream>
#include <string>
using namespace std;

class multiplyString
{
public:
	multiplyString() { }
	~multiplyString() { }
	string solution(string num1,string num2);
};

string multiplyString::solution(string num1,string num2)
{
	if(num1 == "0" || num2 == "0")
		return "0";
	string res;
	int index = 2;
	for(int i=num1.size()-1;i>=0;i--)
	{
		int a = num1[i]-'0';
		string tmp = "";
		int pre = 0;
		for(int j=num2.size()-1;j>=0;j--)
		{
			int b = num2[j]-'0';
			int m = a*b+pre;
			tmp = (char)(m%10+'0')+tmp;
			pre = m/10;
		}
		if(pre != 0)
			tmp = (char)(pre+'0')+tmp;
		if(i == num1.size()-1)
		{
			res = tmp;
			continue;
		}
		int tmp1 = res.size()-index;
		int tmp2 = tmp.size()-1;
		index++;
		pre = 0;
		while(tmp1>=0 && tmp2>=0)
		{
			int m = (res[tmp1]-'0'+tmp[tmp2]-'0')+pre;
			pre = m/10;
			res[tmp1] = (char)(m%10 +'0');
			tmp1--;
			tmp2--;
		}
		while(tmp2>=0)
		{
			int m = tmp[tmp2]-'0'+pre;
			pre = m/10;
			res = (char)(m%10+'0')+res;
			tmp2 --;
		}
		while(tmp1>=0)
		{
			int m = res[tmp1]-'0'+pre;
			pre = m/10;
			res[tmp1] = (char)(m%10+'0');
			tmp1 --;
		}
		if(pre != 0)
			res = (char)(pre+'0')+res;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	multiplyString m;
	cout << m.solution("999", "999") << endl;
	return 0;
}