#include <iostream>
#include <string>
using namespace std;

class validNumber
{
public:
	validNumber() { }
	~validNumber() { }
	bool solution(string s);
};

bool validNumber::solution(string s)
{
	string num = s;
	int i = 0;

	//去掉字符串前后的空格,若存在以及第一个正负号。
	while(num[i] == ' ')
		++i;
	if(num[i] == '+' || num[i] == '-')
		++i;
	int j = num.size() - 1;
	while(num[j] == ' ')
		--j;
	if(i <= j)
		num = num.substr(i,j-i+1);
	else
		return false;

	int dotIndex = -1;//标识点号第一次出现的位置
	int eIndex = -1;//标识e(E)第一次出现的位置

	//判断num是否只由一个点号,一个e(E)后面可能跟着正负号以及数字构成。
	for (int i = 0; i < num.size(); ++i)
	{
		if(dotIndex == -1 && num[i] == '.')
			dotIndex = i;
		else if(eIndex == -1 && (num[i] == 'e' || num[i] == 'E'))
		{
			eIndex = i;
			if(num[i+1] == '+' || num[i+1] == '-')
				++i;
		}
		else{
			int tmp = num[i] - '0';
			if(tmp >= 0 && tmp <= 9)
				continue;
			else
				return false;
		}
	}

	string leftStr,midStr,rightStr;
	if(dotIndex == -1 && eIndex == -1)//xxxxx
		return true;
	else if(dotIndex != -1 && eIndex == -1)//xx.xx(例如：1.2  .12  12.  但是排除只有一个点号的情况)
	{
		leftStr = num.substr(0,dotIndex);
		rightStr = num.substr(dotIndex+1);
		if(leftStr.size() < 1 && rightStr.size() < 1)
			return false;
	}else if(dotIndex == -1 && eIndex != -1)//xxe(E)xxx(例如：1e(+-)2 但是排除e  e(+-)xx  xxxe(+-))
	{
		leftStr = num.substr(0,eIndex);
		if(num[eIndex+1] == '+' || num[eIndex+1] == '-')
			rightStr = num.substr(eIndex+2);
		else
			rightStr = num.substr(eIndex+1);
		if(leftStr.size() < 1 || rightStr.size() < 1)
			return false;
	}else{//xxx.xxexx
		if(dotIndex > eIndex)//xxexx.xx
			return false;
		leftStr = num.substr(0,dotIndex);
		midStr = num.substr(dotIndex+1,eIndex-dotIndex-1);
		if(num[eIndex+1] == '+' || num[eIndex+1] == '-')
			rightStr = num.substr(eIndex+2);
		else
			rightStr = num.substr(eIndex+1);
		if(leftStr.size() < 1 && midStr.size() < 1)//.e(+-)xxx
			return false;
		if(rightStr.size() < 1)//xx.xxe(+-)
			return false;
	}
	return true;
}


int main(int argc, char const *argv[])
{
	string line;
	validNumber v;
	while(getline(cin,line))
	{
		cout << line << "--->";
		cout << v.solution(line) << endl;
	}
	return 0;
}