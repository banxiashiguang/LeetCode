/*KMP算法步骤：
 *(1)先对模式串needle做自匹配，求出字符串中前缀和后缀重复的部分，保存在next数组中。
 *(2)根据next数组的信息，对匹配串haystack和模式串needle做匹配。
 *移动位数 = 已匹配的字符数 - 对应的部分匹配值。
 */

#include <iostream>
#include <string.h>
using namespace std;

class implement_strStr
{
public:
	implement_strStr() { }
	~implement_strStr() { }
	void getNext(const char *patten,int next[]);
	int solution(char *haystack,char *needle);
};

//模式串自匹配
void implement_strStr::getNext(const char *patten,int next[])
{
	int i=0,j=-1;
	next[i] = -1;
	while(i < strlen(patten)-1)
	{
		if(j==-1 || patten[i] == patten[j])
		{
			++i;
			++j;
			next[i] = j;
		}else{
			j = next[j];
		}
	}
	for(int i=0;i<strlen(patten);i++)
	{
		cout<<next[i]<<"\t";
	}
	cout<<endl;
}

//模式串和目标串的匹配
int implement_strStr::solution(char *haystack,char *needle)
{
	int hlen = strlen(haystack);
	int nlen = strlen(needle);
	if(nlen == 0)
		return 0;
	int *next = new int[nlen];
	getNext(needle, next);
	int i = 0;
	int j = 0;
	while(i < hlen && j < nlen)
	{
		if(j == -1 || haystack[i] == needle[j])
		{
			++i;
			++j;
		}else{
			j = next[j];
		}
	}
	delete [] next;
	if(j == nlen)
		return i-nlen;
	else
		return -1;
}

int main(int argc, char const *argv[])
{
	implement_strStr i;
	cout<<i.solution("mississippi", "issi")<<endl;
	return 0;
}