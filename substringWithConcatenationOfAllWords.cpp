/*题意：给定一个字符串S和一个字符串数组L，L中的字符串长度都相等，
 *找出S中所有的子串恰好包含L中所有字符各一次，返回子串的起始位置
 *解题思路：1、利用map<string,int>结构保存L的各个元素的个数。
 	          2、从S中每次取出world_size个元素，若不在map中，i+1;
 	          3、若在map中，判断出现的个数是否等于map中的元素，若大于则break;
 */

#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

class substringWithConcatenationOfAllWords
{
public:
	substringWithConcatenationOfAllWords() { }
	~substringWithConcatenationOfAllWords() { }
	void printMap(map<string,int> &ret);
	vector<int> solution(string S,vector<string> &L);
};

void substringWithConcatenationOfAllWords::printMap(map<string,int> &ret)
{
	for(map<string,int>::const_iterator i=ret.begin();i != ret.end();i++)
		cout<<i->first<<"\t"<<i->second<<endl;
}
vector<int> substringWithConcatenationOfAllWords::solution(string S,vector<string> &L)
{
	map<string,int> tmp;
	vector<int> res;
	int word_size = L[0].size();
	int L_size = L.size();
	int S_size = S.size();
	int i=0,j=0;
	for(int i=0;i<L.size();i++)
	{
		tmp[L[i]]++;
	}
	map<string,int> con;
	for(i=0;i<S_size-L_size*word_size+1;i++)
	{
		con.clear();
		for(j=0;j<L_size;j++)
		{
			string sub= S.substr(i+j*word_size,word_size);
			if(tmp.find(sub) != tmp.end())//L中存在
			{
				con[sub]++;
				if(con[sub] > tmp[sub])
					break;
			}else{//L中不存在
				break;
			}
		}
		if(j == L_size)
			res.push_back(i);
	}
	return res;
}

int main(int argc, char const *argv[])
{
	substringWithConcatenationOfAllWords s;
	vector<string> L;
	L.push_back("foo");
	L.push_back("bar");
	L.push_back("foo");
	vector<int> res = s.solution("barfoofoothefoobarman",L);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<endl;
	return 0;
}