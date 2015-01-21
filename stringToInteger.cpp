/*######################################################
需要考虑的问题主要有一下几个方面
1、一开始空格问题
2、多个正负号的问题
3、转换之后的整数是否越界的问题
######################################################*/

#include <iostream>
#include <climits>
using namespace std;

class stringToInteger
{
public:
	stringToInteger() { }
	~stringToInteger() { }
	int solution(const char *str);
};

int stringToInteger::solution(const char *str)
{
	int flags1=0,flags2=0,i=0;
	long long ret = 0;
	while(*str == ' ')//统计空格数
		str++;
	while(*str == '+' || *str == '-')//统计正负号数目
	{
		if(*str == '+')
		{
			flags1++;
			i++;
		}else{
			flags2++;
			i++;
		}
	}
	if(i > 1)
		return 0;
	while(*str != '\0')
	{
		ret = ret*10 + *str-'0';
		str++;
	}
	if(ret > INT_MAX || ret < INT_MIN)
		return 0;
	if(flags2 == 1)
		return ret*(-1);
	else
		return ret;
}

int main(int argc, char const *argv[])
{
	const char *p = "+13";
	stringToInteger s;
	cout<<s.solution(p)<<endl;
	return 0;
}