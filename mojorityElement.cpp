#include <iostream>
#include <vector>
#include <map>
using namespace std;

class mojorityElement
{
public:
	mojorityElement() { }
	~mojorityElement() { }
	int solution(vector<int> &num);
};

int mojorityElement::solution(vector<int> &num)
{
	map<int,int> tmp;
	for(int i=0;i < num.size();++i)
		++tmp[num[i]];
	int max = 0,element = 0;
	for (auto i = tmp.begin(); i != tmp.end(); ++i)
	{
		if(i->second > max)
		{
			element = i->first;
			max = i->second;
		}
	}
	return max;
}

int main(int argc, char const *argv[])
{
	vector<int> num{2,1,4,7,4,8,3,6,4,7};
	mojorityElement m;
	cout << m.solution(num) << endl;
	return 0;
}