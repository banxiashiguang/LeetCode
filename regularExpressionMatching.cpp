#include <iostream>
#include <cstring>
using namespace std;

class regularExpressionMatching
{
public:
	regularExpressionMatching() { }
	~regularExpressionMatching() { }
	bool solution(const char *s,const char *p);	
};

//递归的实现
bool regularExpressionMatching::solution(const char *s,const char *p)
{
	if(*p == '\0')
		return *s == '\0';
	if(*(p+1) != '*')//下一个不是*
	{
		return ((*p == *s) || (*p == '.' && *s != '\0')) && regularExpressionMatching(s+1,p+1);
	}

	while((*p == *s) || (*p == '.' && *s != '\0'))//下一个是*
	{
		if(solution(s, p+2))
			return true;
		s++;
	}
	return solution(s, p+2);
}